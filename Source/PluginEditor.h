#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class KickBabyAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    KickBabyAudioProcessorEditor (KickBabyAudioProcessor&);
    ~KickBabyAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    KickBabyAudioProcessor& processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KickBabyAudioProcessorEditor)
};