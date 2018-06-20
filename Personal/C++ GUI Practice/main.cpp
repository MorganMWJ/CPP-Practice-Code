#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Variable for child window(for static text) of main window  */
HWND textField, button, button2, textBox, textBoxButton;

char textInput[25];

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("GUI Practice"),       /* Title Text */
           WS_MINIMIZEBOX | WS_SYSMENU, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            textField = CreateWindow("STATIC",
                                     "Text Field",//static text
                                     WS_VISIBLE | WS_BORDER | WS_CHILD,
                                     20,20,80,25,
                                     hwnd,
                                     NULL,NULL,NULL);

            textBox = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_BORDER | WS_CHILD,
                                   95,20,250,25,
                                   hwnd,
                                   NULL,NULL,NULL);

            button = CreateWindow("BUTTON",
                                  "This is a Button",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  200,200,150,25,
                                  hwnd,
                                  (HMENU) 1,NULL,NULL);//9th parameter is an integer value identifier to notify parent about events

            button = CreateWindow("BUTTON",
                                  "Exit Program",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  200,300,150,25,
                                  hwnd,
                                  (HMENU) 2,NULL,NULL);//9th parameter is an integer value identifier to notify parent about events
            button = CreateWindow("BUTTON",
                                  "Enter",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  345,20,50,25,
                                  hwnd,
                                  (HMENU) 3,NULL,NULL);
            break;
        case WM_COMMAND://case is true when ever something is clicked/activated
            switch (LOWORD(wParam))//another switch statement to do different things dependent upon what is clicked
            {
                case 1:
                    ::MessageBeep(MB_ICONINFORMATION);
                    ::MessageBox(hwnd,"You clicked the button", "Pop-up",MB_OK); // '::' refers to the function or variable after it being in the global namespace
                    break;
                case 2:
                    PostQuitMessage (0);
                    break;
                case 3:
                    int successRead = 0;
                    successRead = GetWindowText(textBox,&textInput[0],25);
                    // '&textInput[0]' is correct because the function needs a string and you can pass char arrays into functions by giving the address of the first element
                    //GetWindowText returns the number of characters read or 0 if error
                    //GetWindowText has now saved the input into the textInput array
                    ::MessageBox(hwnd,&textInput[0],"Text Input",MB_OK);
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
