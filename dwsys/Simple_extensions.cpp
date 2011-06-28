/* Simple_extensions.cpp
 *
 * Copyright (C) 1994-2011 David Weenink
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 djmw 20020812 GPL header
 djmw & pb wchar_t
*/

#include "Simple_extensions.h"
#include "longchar.h"

void SimpleString_init (SimpleString me, const wchar_t *string)
{
	try {
		my string = Melder_wcsdup (string);
	} catch (MelderError) { rethrow; }
}

int SimpleString_compare (SimpleString me, SimpleString thee)
{
	return wcscmp (my string, thy string);
}

const wchar_t *SimpleString_c (SimpleString me)
{
    return my string;
}

void SimpleString_append (SimpleString me, SimpleString thee)
{
    SimpleString_append_c (me, thy string); 
}

void SimpleString_append_c (SimpleString me, const wchar_t *str)
{
	try {
		if (str == 0) return;
		long myLength = wcslen (my string);
		my string = (wchar_t *) Melder_realloc (my string, (myLength + wcslen (str) + 1) * sizeof (wchar_t));
		wcscpy (& my string[myLength], str);
	} catch (MelderError) { rethrow; }	
}

SimpleString SimpleString_concat (SimpleString me, SimpleString thee)
{
	try {
		autoSimpleString him = (SimpleString) Data_copy (me);
		SimpleString_append_c (him.peek(), thy string);
		return him.transfer();
	} catch (MelderError) { rethrowzero; }
}

SimpleString SimpleString_concat_c (SimpleString me, const wchar_t *str)
{
	try {
		autoSimpleString him = (SimpleString) Data_copy (me);
		SimpleString_append_c (him.peek(), str);
		return him.transfer(); 		
	} catch (MelderError) { rethrowzero; }
}

void SimpleString_replace_c (SimpleString me, const wchar_t *str)
{
	try {
		wchar_t *ptr = Melder_wcsdup (str);
		Melder_free (my string);
		my string = ptr;
	} catch (MelderError) { rethrow; }
}

long SimpleString_length (SimpleString me)
{
    return wcslen (my string);
}

void SimpleString_draw (SimpleString me, Any g, double xWC, double yWC)
{
    Graphics_text (g, xWC, yWC, my string);
}

const wchar_t * SimpleString_nativize_c (SimpleString me, int educateQuotes)
{
	try {
		autoSimpleString thee = (SimpleString) Data_copy (me);
		Longchar_nativizeW (thy string, my string, educateQuotes);
		forget (thee);
		return my string;
	} catch (MelderError) { rethrowzero; }
}

const wchar_t * SimpleString_genericize_c (SimpleString me)
{
	try {
		autoSimpleString thee = (SimpleString) Data_copy (me);
		my string = (wchar_t *) Melder_realloc (my string, 3 * wcslen (my string) * sizeof (wchar_t));
		Longchar_genericizeW (thy string, my string);
		return my string;
	} catch (MelderError) { rethrowzero; }
}

/* End of file Simple_extensions.cpp */