#ifndef _OTMultiEditor_h_
#define _OTMultiEditor_h_
/* OTMultiEditor.h
 *
 * Copyright (C) 2005-2011,2012,2015 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "HyperPage.h"
#include "OTMulti.h"

Thing_define (OTMultiEditor, HyperPage) {
	const char32 *form1, *form2;
	GuiText form1Text, form2Text;
	long selectedConstraint;
	bool d_constraintsAreDrawnVertically;

	bool v_editable ()
		override { return true; }
	void v_createChildren ()
		override;
	void v_createMenus ()
		override;
	void v_createHelpMenuItems (EditorMenu menu)
		override;
	void v_draw ()
		override;
	int v_goToPage (const char32 *title)
		override;
};

autoOTMultiEditor OTMultiEditor_create (const char32 *title, OTMulti grammar);

/* End of file OTMultiEditor.h */
#endif
