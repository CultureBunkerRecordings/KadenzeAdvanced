/*
  ==============================================================================

    KAPInterfaceDefines.h
    Created: 20 Dec 2021 10:59:16pm
    Author:  William

  ==============================================================================
*/
#include <JuceHeader.h>

#pragma once

#define MainPanelWidth 750
#define MainPanelHeight 300

#define TopPanelWidth MainPanelWidth
#define TopPanelHeight 45

#define GainPanelWidth 100
#define GainPanelHeight MainPanelHeight - TopPanelHeight

#define CentrePanelWidth MainPanelWidth - (GainPanelWidth*2)
#define CentrePanelHeight GainPanelHeight

#define CentreMenuPanelWidth CentrePanelWidth
#define CentreMenuPanelHeight 35

#define FXPanelWidth CentrePanelWidth
#define FXPanelHeight CentrePanelHeight - CentreMenuPanelHeight






