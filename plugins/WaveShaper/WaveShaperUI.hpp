#ifndef WAVESHAPER_UI_HPP_INCLUDED
#define WAVESHAPER_UI_HPP_INCLUDED

#include "DistrhoUI.hpp"
#include "GraphWidgetSocket.hpp"
#include "RemoveDCSwitch.hpp"
#include "ResetGraphButton.hpp"
#include "OversampleWheel.hpp"

START_NAMESPACE_DISTRHO

enum Parameters
{
  paramPreGain = 0,
  paramWet,
  paramPostGain,
  paramRemoveDC,
  paramOversample,
  paramBipolarMode,
  paramOut,
  paramCount
};

class WaveShaperUI : public UI,
                     public NanoSwitch::Callback,
                     public NanoButton::Callback,
                     public NanoWheel::Callback
{
public:
  WaveShaperUI();
  ~WaveShaperUI();

  float getParameterValue(uint32_t index) const;

protected:
  void parameterChanged(uint32_t, float value) override;

  void nanoSwitchClicked(NanoSwitch *nanoSwitch);

  void nanoButtonClicked(NanoButton *nanoButton);

  void nanoWheelValueChanged(NanoWheel *nanoWheel, int value);
  
  void stateChanged(const char *key, const char *value) override;
  void onNanoDisplay() override;
  void uiIdle() override;

private:
  float parameters[paramCount];

  ScopedPointer<RemoveDCSwitch> fSwitchRemoveDC;
  ScopedPointer<ResetGraphButton> fButtonResetGraph;
  ScopedPointer<OversampleWheel> fWheelOversample;

  //ScopedPointer<ImageKnob> fKnobPre, fKnobDryWet, fKnobPost;

  GraphWidgetSocket graphWidgetSocket;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveShaperUI)
};

END_NAMESPACE_DISTRHO

#endif