/*
 * Copyright 2004-2010 Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Author:
 * 		Davide Gessa, dak.linux@gmail.com
 */
#ifndef NETWORK_VIEW_H
#define NETWORK_VIEW_H


#include <View.h>


class BButton;


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
