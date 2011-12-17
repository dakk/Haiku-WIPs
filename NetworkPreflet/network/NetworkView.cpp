/*
 * Copyright 2004-2010 Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 * 		Davide Gessa, dak.linux@gmail.com
 */


#include "NetworkView.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <Alert.h>
#include <Application.h>
#include <Beep.h>
#include <Box.h>
#include <Button.h>
#include <Catalog.h>
#include <Directory.h>
#include <File.h>
#include <FindDirectory.h>
#include <GridView.h>
#include <GroupView.h>
#include <MenuField.h>
#include <MenuItem.h>
#include <NetworkDevice.h>
#include <NetworkInterface.h>
#include <NetworkRoster.h>
#include <Path.h>
#include <PopUpMenu.h>
#include <Slider.h>
#include <SpaceLayoutItem.h>
#include <String.h>
#include <StringView.h>
#include <TextControl.h>

#include <AutoDeleter.h>

#include "Settings.h"


static const uint32 kMsgNewNetwork = 'aply';
static const uint32 kMsgRefresh = 'rvrt';
static const uint32 kMsgClose = 'clse';



#undef B_TRANSLATE_CONTEXT
#define B_TRANSLATE_CONTEXT "NetworkView"


NetworkView::NetworkView()
	:
	BView("NetworkView", 0, NULL)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));


	// build the GUI
	BGroupLayout* rootLayout = new BGroupLayout(B_VERTICAL);
	SetLayout(rootLayout);

	//BGridView* controlsGroup = new BGridView();
	//BGridLayout* layout = controlsGroup->GridLayout();

	// insets
	/*
	float inset = ceilf(be_plain_font->Size() * 0.7);
	rootLayout->SetInsets(inset, inset, inset, inset);
	rootLayout->SetSpacing(inset);
	layout->SetSpacing(inset, inset);
	*/
	// available network lists



	// button group
	BGroupView* buttonGroup = new BGroupView(B_HORIZONTAL);

	fRefreshButton = new BButton(B_TRANSLATE("Refresh"),
		new BMessage(kMsgRefresh));
	fRefreshButton->SetEnabled(false);
	buttonGroup->GroupLayout()->AddView(fRefreshButton);

	buttonGroup->GroupLayout()->AddItem(BSpaceLayoutItem::CreateGlue());

	fNewNetworkButton = new BButton(B_TRANSLATE("New Network"), new BMessage(kMsgNewNetwork));
	fNewNetworkButton->SetEnabled(false);
	buttonGroup->GroupLayout()->AddView(fNewNetworkButton);

	//rootLayout->AddView(controlsGroup);
	rootLayout->AddView(buttonGroup);
}


NetworkView::~NetworkView()
{
}


void
NetworkView::AttachedToWindow()
{
	fRefreshButton->SetTarget(this);
	fNewNetworkButton->SetTarget(this);
}


void
NetworkView::DetachedFromWindow()
{
}


void
NetworkView::MessageReceived(BMessage* message)
{
	switch (message->what) {
		case kMsgRefresh:
			break;
		case kMsgNewNetwork:
			break;
		default:
			BView::MessageReceived(message);
	}
}

