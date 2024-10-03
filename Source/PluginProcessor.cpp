#include "PluginProcessor.h"

KickBabyAudioProcessor::KickBabyAudioProcessor()
    : osc ([](float x) { return std::sin (x); }),       // Sine wave for the kick
      bassOsc ([](float x) { return std::sin (x); })    // Sine wave for the bass
{
    // Initialize Kick envelope (ADSR)
    adsrParams.attack = 0.01f;
    adsrParams.decay = 0.2f;
    adsrParams.sustain = 0.5f;
    adsrParams.release = 0.3f;
    adsr.setParameters(adsrParams);
}

KickBabyAudioProcessor::~KickBabyAudioProcessor() {}

void KickBabyAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Prepare oscillators and reset envelope
    osc.prepare({ sampleRate, (juce::uint32) samplesPerBlock, 1 });
    bassOsc.prepare({ sampleRate, (juce::uint32) samplesPerBlock, 1 });
    adsr.reset();
}

void KickBabyAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
    {
        float output = 0.0f;

        // Kick on the 1st beat, bass on the next 3 beats
        if (beatCounter == 0) 
        {
            float oscOutput = osc.processSample(0.0f);  // Kick oscillator
            float envelopeValue = adsr.getNextSample(); // Kick envelope
            output = envelopeValue * oscOutput;
        }
        else 
        {
            float bassOutput = bassOsc.processSample(0.0f); // Bass oscillator
            output = bassOutput * 0.8f;                    // Lower volume for bass
        }

        // Write output to the buffer
        buffer.setSample(0, sample, output);

        // Increment beat counter and reset after 4 beats
        if (++beatCounter >= 4) 
            beatCounter = 0;
    }
}