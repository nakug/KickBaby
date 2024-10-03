#include "PluginEditor.h"

KickBabyAudioProcessorEditor::KickBabyAudioProcessorEditor (KickBabyAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    setSize (400, 300);
}

KickBabyAudioProcessorEditor::~KickBabyAudioProcessorEditor() {}

void KickBabyAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("KickBaby VST", getLocalBounds(), juce::Justification::centred, 1);
}

void KickBabyAudioProcessorEditor::resized()
{
}