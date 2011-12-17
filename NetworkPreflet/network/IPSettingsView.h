/*
 * Copyright 2004-2010 Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Author:
 *		Andre Alves Garzia, andre@andregarzia.com
 *		Axel Dörfler
 *		Hugo Santos
 *		Vegard Wærp
 * 		Davide Gessa, dak.linux@gmail.com
 */
#ifndef IP_SETTINGS_VIEW_H
#define IP_SETTINGS_VIEW_H


#include <ObjectList.h>
#include <View.h>

#include <posix/regex.h>


class BButton;
class BMenuField;
class BPath;
class BTextControl;
class BStringView;
class Settings;
class BNetworkInterface;


class IPSettingsView : public BView {
public:
								IPSettingsView(BNetworkInterface *interface, Settings *settings);
		virtual					~IPSettingsView();

protected:
		virtual	void			AttachedToWindow();
		virtual	void			DetachedFromWindow();
		virtual	void			MessageReceived(BMessage* message);

private:
				void 			_ShowConfiguration(Settings* settings);
				void			_EnableTextControls(bool enable);
				void			_SaveConfiguration();
				void			_SaveDNSConfiguration();
				void			_SaveAdaptersConfiguration();
				void			_ApplyControlsToConfiguration();
				status_t		_GetPath(const char* name, BPath& path);
				status_t		_TriggerAutoConfig(const char* device);

				bool			_ValidateControl(BTextControl* control);
private:

				BButton*		fApplyButton;
				BButton*		fRevertButton;
					// TODO: buttons should be moved to window instead

				BMenuField*		fDeviceMenuField;
				BMenuField*		fNetworkMenuField;
				BMenuField*		fTypeMenuField;
				BTextControl*	fIPTextControl;
				BTextControl*	fNetMaskTextControl;
				BTextControl*	fGatewayTextControl;

				BTextControl*	fPrimaryDNSTextControl;
				BTextControl*	fSecondaryDNSTextControl;
				BTextControl*	fDomainTextControl;

				BStringView*	fErrorMessage;

					// TODO: DNS settings do not belong here, do they?
				BNetworkInterface *fInterface;
					// TODO: the view should not know about the interfaces,
					// it should only display the given interface, move
					// one level up.
				Settings *fSettings;
					// TODO: the view should not know about a list
					// of settings, instead it should be configured
					// to a specific setting from the code one level up

				int32			fStatus;
				int				fSocket;
};

#endif /* IP_SETTINGS_VIEW_H */
