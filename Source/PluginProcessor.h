#pragma once

#include <JuceHeader.h>

class KickBabyAudioProcessor : public juce::AudioProcessor
{
public:
    KickBabyAudioProcessor();
    ~KickBabyAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

private:
    juce::dsp::Oscillator<float> osc;        // Kick oscillator
    juce::dsp::Oscillator<float> bassOsc;    // Bass oscillator
    juce::ADSR adsr;                         // Kick envelope
    juce::ADSR::Parameters adsrParams;
    int beatCounter = 0;                     // Tracks the 4/4 pattern

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KickBabyAudioProcessor)
};