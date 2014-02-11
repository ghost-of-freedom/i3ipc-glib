/*
 * This file is part of i3-ipc.
 *
 * i3-ipc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * i3-ipc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with i3-ipc.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright © 2014, Tony Crisci
 *
 */

#ifndef __I3IPC_CON_H__
#define __I3IPC_CON_H__

#include <glib-object.h>

/**
  * SECTION: i3ipc-con
  * @short_description: A representation of an i3 window container.
  *
  * #i3ipcCon is a class to model a node in the i3 window container tree.
  *
  */

#define I3IPC_TYPE_CON             (i3ipc_con_get_type ())
#define I3IPC_CON(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), I3IPC_TYPE_CON, i3ipcCon))
#define I3IPC_IS_CON(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), I3IPC_TYPE_CON))
#define I3IPC_CON_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), I3IPC_TYPE_CON, i3ipcConClass))
#define I3IPC_IS_CON_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), I3IPC_TYPE_CON))
#define I3IPC_CON_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), I3IPC_TYPE_CON, i3ipcConClass))

typedef struct _i3ipcCon        i3ipcCon;
typedef struct _i3ipcConClass   i3ipcConClass;
typedef struct _i3ipcConPrivate i3ipcConPrivate;

struct _i3ipcCon
{
  GObject parent_instance;

  /* instance members */
  gint id;
  gchar *name;
  gchar *border;
  gint current_border_width;
  gchar *layout;
  gchar *orientation;
  gfloat percent;
  gint window;
  gboolean urgent;
  gboolean focused;

  i3ipcConPrivate *priv;
};

struct _i3ipcConClass
{
  GObjectClass parent_class;

  /* class members */
};

/* used by I3IPC_TYPE_CON */
GType i3ipc_con_get_type(void);

i3ipcCon *i3ipc_con_new(void);

/* Method definitions */

#endif