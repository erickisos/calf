/* Calf DSP Library
 * A knob (dial) widget.
 *
 * Copyright (C) 2008-2010 Krzysztof Foltman, Torben Hohn, Markus
 * Schmidt and others
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, 
 * Boston, MA 02111-1307, USA.
 */

#ifndef CALF_CTL_KNOB_H
#define CALF_CTL_KNOB_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CALF_TYPE_KNOB          (calf_knob_get_type())
#define CALF_KNOB(obj)          (G_TYPE_CHECK_INSTANCE_CAST ((obj), CALF_TYPE_KNOB, CalfKnob))
#define CALF_IS_KNOB(obj)       (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CALF_TYPE_KNOB))
#define CALF_KNOB_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST ((klass),  CALF_TYPE_KNOB, CalfKnobClass))
#define CALF_IS_KNOB_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE ((klass),  CALF_TYPE_KNOB))

struct CalfKnobSizes
{
    int size;
    float light_rad;
    float mask_rad;
    float mask_width;
    double dash[2];
    int dash_length;
    float dot_rad;
    float dot_width;
    float dot_length;
} 
struct CalfKnob
{
    GtkRange parent;
    int knob_type;
    int knob_size;
    int size;
    double start_x, start_y, last_y, start_value, default_value;
    const CalfKnobSizes sizes[4] = {
         20,  8,  8, 1.5, {1, 0}, 0, 15,   1,   1,
         40,  9, 18,   2, {2, 2}, 2, 15,   1,   3,
         60, 10, 22,   3, {3, 3}, 2, 18,   1, 2.5,
         80, 12, 32,   4, {3, 3}, 2, 28,   1,   3,
        100, 14, 44,   4, {4, 4}, 2, 38, 1.5,   4
    };
};

struct CalfKnobClass
{
    GtkRangeClass parent_class;
    GdkPixbuf *knob_image[5];
};

extern GtkWidget *calf_knob_new();
extern GtkWidget *calf_knob_new_with_adjustment(GtkAdjustment *_adjustment);

extern GType calf_knob_get_type();

G_END_DECLS

#endif
