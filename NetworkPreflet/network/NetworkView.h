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
#ifndef NETWORK_VIEW_H
#define NETWORK_VIEW_H


#include <ObjectList.h>
#include <View.h>

#include <posix/regex.h>


class BButton;
class BMenuField;
class BPath;
class BTextControl;
class BStringView;
class Settings;


class NetworkView : public BView {
public:
								NetworkView();
		virtual					~NetworkView();

protected:
		virtual	void			AttachedToWindow();
		virtual	void			DetachedFromWindow();
		virtual	void			MessageReceived(BMessage* message);

private:
				BButton*		fRefreshButton;
				BButton*		fNewNetworkButton;
};

#endif /* NETWORK_VIEW_H */
