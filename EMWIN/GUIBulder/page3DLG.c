/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.26                          *
*        Compiled Aug 18 2014, 17:12:05                              *
*        (c) 2014 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "device_info.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_2     (GUI_ID_USER + 0x30)
#define ID_GRAPH_30     (GUI_ID_USER + 0x31)
#define ID_CHECKBOX_30     (GUI_ID_USER + 0x32)
#define ID_CHECKBOX_31     (GUI_ID_USER + 0x33)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogpage3Create
*/
static const GUI_WIDGET_CREATE_INFO _aDialogpage3Create[] = {
  { WINDOW_CreateIndirect, "page3", ID_WINDOW_2, 0, 0, 310, 120, 0, 0x0, 0 },
  { GRAPH_CreateIndirect, "allhumi", ID_GRAPH_30, 0, 24, 306, 76, 0, 0x0, 2 },
  { CHECKBOX_CreateIndirect, "hum1", ID_CHECKBOX_30, 50, 2, 80, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "humi2", ID_CHECKBOX_31, 180, 1, 80, 20, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbpage3Dialog
*/
static void _cbpage3Dialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	  
	hItem = pMsg->hWin;
	WINDOW_SetBkColor(hItem, GUI_DARKCYAN);  
    //
    // Initialization of 'allhumi'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_30);
    GRAPH_SetBorder(hItem, 2, 2, 2, 2);
    //
    // Initialization of 'hum1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_30);
    CHECKBOX_SetText(hItem, "ʪ��1");
    CHECKBOX_SetTextColor(hItem, 0x0000ca00);
  	CHECKBOX_SetFont(hItem,&GUI_FontHZ12);
    //
    // Initialization of 'humi2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_31);
    CHECKBOX_SetText(hItem, "ʪ��2");
    CHECKBOX_SetTextColor(hItem, 0x000d86ff);
  	CHECKBOX_SetFont(hItem,&GUI_FontHZ12);  
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_CHECKBOX_30: // Notifications sent by 'hum1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_31: // Notifications sent by 'humi2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       Createpage3
*/
WM_HWIN Createpage3(void);
WM_HWIN Createpage3(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogpage3Create, GUI_COUNTOF(_aDialogpage3Create), _cbpage3Dialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/