#include <windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int	WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpszCmdLine, int nCmdShow)
{
		WNDCLASS wc;
        HWND hwnd;
		MSG msg;
		/***************** 1. Define Windows class ****************************/
		wc.style = 0; // Class style
		wc.lpfnWndProc = (WNDPROC) WndProc; // Window procedure address
		wc.cbClsExtra = 0; // Class extra bytes
		wc.cbWndExtra = 0; // Window extra bytes
		wc.hInstance = hInstance; // Instance handle
		wc.hIcon = LoadIcon (NULL,IDI_QUESTION); // Icon handle
		wc.hCursor = LoadCursor (NULL, IDC_HELP); // Cursor handle
		wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 12); // Background color
		wc.lpszMenuName = NULL; // Menu name
		wc.lpszClassName = "Naphorn"; // WNDCLASS name

		/***************** 2. Register the Windows class **********************/

		RegisterClass (&wc);

		/***************** 3. Create window **********************/
		hwnd = CreateWindow (
				"Naphorn", // WNDCLASS name
				"Naphorn Chokpokasombat", // Window title
				WS_OVERLAPPEDWINDOW, // Window style
				CW_USEDEFAULT, // Horizontal position
   				CW_USEDEFAULT, // Vertical position
               	CW_USEDEFAULT, // Initial width
               	CW_USEDEFAULT, // Initial height
				HWND_DESKTOP, // Handle of parent window
				NULL, // Menu handle
				hInstance, // Application's instance handle
				NULL // Window-creation data
		);

		/***************** 4. Display the window **********************/
		ShowWindow (hwnd, nCmdShow);
		UpdateWindow (hwnd);

		/***************** 5. Message loop **********************/
		while (GetMessage (&msg, NULL, 0, 0)) {
				TranslateMessage (&msg);
				DispatchMessage (&msg);
		}
		return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam,
			LPARAM lParam)
{
			PAINTSTRUCT ps;
			HDC hdc;

			switch (message) {

			case WM_PAINT:
				hdc = BeginPaint (hwnd, &ps);
				//Rectangle (hdc, 40, 40, 260, 260);
				//Rectangle (hdc, 40, 600, 260, 260);
				//Leg
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 50, 410, 150, 450);
				Ellipse (hdc, 150, 410, 250, 450);
				//Arm
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 25, 262, 125, 315);
				Ellipse (hdc, 175, 262, 275, 315);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 5, 305, 50, 270);
				Ellipse (hdc, 295, 305, 250, 270);
				//Body
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 58, 238, 240, 430);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 75, 245, 225, 390);
				//Bag
				Chord(hdc,92,370,208,220,40,362,322,400);
				//Face
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 40, 40, 260, 260);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 60, 90, 240, 260);
				//Eye1
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 90, 55, 150, 128);
				Ellipse (hdc, 150, 55, 210, 128);
				//Eye2
				SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
				Ellipse (hdc, 95, 80, 145, 128);
				Ellipse (hdc, 155, 80, 205, 128);
				//Eye3
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 128, 105, 142, 121);
				Ellipse (hdc, 158, 105, 172, 121);
				//Nose Red
				SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
				Ellipse (hdc, 165, 116, 135, 144);
				//Nose Shadow
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 162, 131, 152, 142);
				//FaceLine
				MoveToEx(hdc, 150, 143, NULL); LineTo(hdc, 150, 190);
				///Light
				MoveToEx(hdc, 65, 132, NULL); LineTo(hdc, 135, 146);
				MoveToEx(hdc, 55, 152, NULL); LineTo(hdc, 135, 158);
				MoveToEx(hdc, 65, 175, NULL); LineTo(hdc, 135, 170);
				///Right
				MoveToEx(hdc, 235, 132, NULL); 	LineTo(hdc, 165, 146);
				MoveToEx(hdc, 235, 152, NULL); 	LineTo(hdc, 165, 158);
				MoveToEx(hdc, 235, 175, NULL); 	LineTo(hdc, 165, 170);
				//Lip
				SelectObject(hdc,CreateSolidBrush(RGB(255,70,0)));
				Chord(hdc,84,100,215,240,101,185,300,217);
				//Neck
				SelectObject(hdc,CreatePen(PS_DASH, 17, RGB(255,0,0)));
				MoveToEx(hdc, 92, 255, NULL); LineTo(hdc, 205, 255);
				//Ring
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
				Ellipse (hdc, 163, 268, 138, 245);

				/**2*****************************************************/
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				//Leg
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 340, 215, 395, 240);
				Ellipse (hdc, 395, 215, 450, 240);
				//Arm
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 320, 140, 400, 170);
				Ellipse (hdc, 395, 140, 470, 170);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 315, 142, 335, 170);
				Ellipse (hdc, 475, 142, 455, 170);
				//Body
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 340, 133, 450, 230);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 351, 135, 440, 205);
				//Bag
				Chord(hdc,365,190,425,135,240,145,420,160);
				//Face
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 330, 10, 460, 140);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 345, 45, 445, 140);
				//Eye1
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 370, 30, 395, 62);
				Ellipse (hdc, 395, 30, 420, 62);
				//Eye2
				SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
				Ellipse (hdc, 373, 40, 392, 62);
				Ellipse (hdc, 398, 40, 417, 62);
				//Eye3
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 383, 52, 390, 59);
				Ellipse (hdc, 400, 52, 407, 59);
				//Nose Red
				SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
				Ellipse (hdc, 402, 58, 388, 71);
				//Nose Shadow
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 400, 65, 396, 69);
				//FaceLine
				MoveToEx(hdc, 395, 70, NULL); LineTo(hdc, 395, 100);
				///Light
				MoveToEx(hdc, 350, 68, NULL); LineTo(hdc, 388, 74);
				MoveToEx(hdc, 348, 79, NULL); LineTo(hdc, 388, 81);
				MoveToEx(hdc, 350, 91, NULL); LineTo(hdc, 388, 87);
				///Right
				MoveToEx(hdc, 440, 68, NULL); 	LineTo(hdc, 402, 74);
				MoveToEx(hdc, 442, 79, NULL); 	LineTo(hdc, 402, 81);
				MoveToEx(hdc, 440, 91, NULL); 	LineTo(hdc, 402, 87);
				//Lip
				SelectObject(hdc,CreateSolidBrush(RGB(255,70,0)));
				Chord(hdc,355,35,435,125,200,182,602,184);
      			//Neck
				SelectObject(hdc,CreatePen(PS_DASH, 10, RGB(255,0,0)));
				MoveToEx(hdc, 365, 138, NULL);
				LineTo(hdc, 425, 138);
				//Ring
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
				Ellipse (hdc, 388, 145, 403, 130);

				/**3*********************/
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				//Leg
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+340, 215, 180+395, 240);
				Ellipse (hdc, 180+395, 215, 180+450, 240);
				//Arm
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 180+320, 140, 180+400, 170);
				Ellipse (hdc, 180+395, 140, 180+470, 170);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+315, 142, 180+335, 170);
				Ellipse (hdc, 180+475, 142, 180+455, 170);
				//Body
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 180+340, 133, 180+450, 230);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+351, 135, 180+440, 205);
				//Bag
				Chord(hdc,180+365,190,180+425,135,180+240,145,180+420,160);
				//Face
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 180+330, 10, 180+460,140);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+345, 45, 180+445, 140);
				//Eye1
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+370, 30, 180+395, 62);
				Ellipse (hdc, 180+395, 30, 180+420, 62);
				//Eye2
				SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
				Ellipse (hdc, 180+373, 40, 180+392, 62);
				Ellipse (hdc, 180+398, 40, 180+417, 62);
				//Eye3
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+383, 52, 180+390, 59);
				Ellipse (hdc, 180+400, 52, 180+407, 59);
				//Nose Red
				SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
				Ellipse (hdc, 180+402, 58, 180+388, 71);
				//Nose Shadow
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+400, 65, 180+396, 69);
				//FaceLine
				MoveToEx(hdc, 180+395, 70, NULL); LineTo(hdc, 180+395, 100);
				///Light
				MoveToEx(hdc, 180+350, 68, NULL); LineTo(hdc, 180+388, 74);
				MoveToEx(hdc, 180+348, 79, NULL); LineTo(hdc, 180+388, 81);
				MoveToEx(hdc, 180+350, 91, NULL); LineTo(hdc, 180+388, 87);
				///Right
				MoveToEx(hdc, 180+440, 68, NULL); 	LineTo(hdc, 180+402, 74);
				MoveToEx(hdc, 180+442, 79, NULL); 	LineTo(hdc, 180+402, 81);
				MoveToEx(hdc, 180+440, 91, NULL); 	LineTo(hdc, 180+402, 87);
				//Lip
				SelectObject(hdc,CreateSolidBrush(RGB(255,70,0)));
				Chord(hdc,180+355,35,180+435,125,180+200,182,180+602,184);
      			//Neck
				SelectObject(hdc,CreatePen(PS_DASH, 10, RGB(255,0,0)));
				MoveToEx(hdc, 180+365, 138, NULL);
				LineTo(hdc, 180+425, 138);
				//Ring
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
				Ellipse (hdc, 180+388, 145, 180+403, 130);

				//////**4**********************/
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				//Leg
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+340, 215, 180+180+395, 240);
				Ellipse (hdc, 180+180+395, 215, 180+180+450, 240);
				//Arm
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 180+180+320, 140, 180+180+400, 170);
				Ellipse (hdc, 180+180+395, 140, 180+180+470, 170);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+315, 142, 180+180+335, 170);
				Ellipse (hdc, 180+180+475, 142, 180+180+455, 170);
				//Body
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 180+180+340, 133, 180+180+450, 230);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+351, 135, 180+180+440, 205);
				//Bag
				Chord(hdc,180+180+365,190,180+180+425,135,180+180+240,145,180+180+420,160);
				//Face
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 180+180+330, 10, 180+180+460,140);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+345, 45, 180+180+445, 140);
				//Eye1
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+370, 30, 180+180+395, 62);
				Ellipse (hdc, 180+180+395, 30, 180+180+420, 62);
				//Eye2
				SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
				Ellipse (hdc, 180+180+373, 40, 180+180+392, 62);
				Ellipse (hdc, 180+180+398, 40, 180+180+417, 62);
				//Eye3
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+383, 52, 180+180+390, 59);
				Ellipse (hdc, 180+180+400, 52, 180+180+407, 59);
				//Nose Red
				SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
				Ellipse (hdc, 180+180+402, 58, 180+180+388, 71);
				//Nose Shadow
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 180+180+400, 65, 180+180+396, 69);
				//FaceLine
				MoveToEx(hdc, 180+180+395, 70, NULL); LineTo(hdc, 180+180+395, 100);
				///Light
				MoveToEx(hdc, 180+180+350, 68, NULL); LineTo(hdc, 180+180+388, 74);
				MoveToEx(hdc, 180+180+348, 79, NULL); LineTo(hdc, 180+180+388, 81);
				MoveToEx(hdc, 180+180+350, 91, NULL); LineTo(hdc, 180+180+388, 87);
				///Right
				MoveToEx(hdc, 180+180+440, 68, NULL); 	LineTo(hdc, 180+180+402, 74);
				MoveToEx(hdc, 180+180+442, 79, NULL); 	LineTo(hdc, 180+180+402, 81);
				MoveToEx(hdc, 180+180+440, 91, NULL); 	LineTo(hdc, 180+180+402, 87);
				//Lip
				SelectObject(hdc,CreateSolidBrush(RGB(255,70,0)));
				Chord(hdc,180+180+355,35,180+180+435,125,180+180+200,182,180+180+602,184);
      			//Neck
				SelectObject(hdc,CreatePen(PS_DASH, 10, RGB(255,0,0)));
				MoveToEx(hdc, 180+180+365, 138, NULL);
				LineTo(hdc, 180+180+425, 138);
				//Ring
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
				Ellipse (hdc, 180+180+388, 145, 180+180+403, 130);

				//////**4**********************/
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				//Leg
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+340, 215, 170+180+180+395, 240);
				Ellipse (hdc, 170+180+180+395, 215, 170+180+180+450, 240);
				//Arm
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 170+180+180+320, 140, 170+180+180+400, 170);
				Ellipse (hdc, 170+180+180+395, 140, 170+180+180+470, 170);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+315, 142, 170+180+180+335, 170);
				Ellipse (hdc, 170+180+180+475, 142, 170+180+180+455, 170);
				//Body
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 170+180+180+340, 133, 170+180+180+450, 230);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+351, 135, 170+180+180+440, 205);
				//Bag
				Chord(hdc,170+180+180+365,190,170+180+180+425,135,170+180+180+240,145,170+180+180+420,160);
				//Face
				SelectObject(hdc,CreateSolidBrush(RGB(27,134,240)));
				Ellipse (hdc, 170+180+180+330, 10, 170+180+180+460,140);
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+345, 45, 170+180+180+445, 140);
				//Eye1
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+370, 30, 170+180+180+395, 62);
				Ellipse (hdc, 170+180+180+395, 30, 170+180+180+420, 62);
				//Eye2
				SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
				Ellipse (hdc, 170+180+180+373, 40, 170+180+180+392, 62);
				Ellipse (hdc, 170+180+180+398, 40, 170+180+180+417, 62);
				//Eye3
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+383, 52, 170+180+180+390, 59);
				Ellipse (hdc, 170+180+180+400, 52, 170+180+180+407, 59);
				//Nose Red
				SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
				Ellipse (hdc, 170+180+180+402, 58, 170+180+180+388, 71);
				//Nose Shadow
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
				Ellipse (hdc, 170+180+180+400, 65, 170+180+180+396, 69);
				//FaceLine
				MoveToEx(hdc, 170+180+180+395, 70, NULL); LineTo(hdc, 170+180+180+395, 100);
				///Light
				MoveToEx(hdc, 170+180+180+350, 68, NULL); LineTo(hdc, 170+180+180+388, 74);
				MoveToEx(hdc, 170+180+180+348, 79, NULL); LineTo(hdc, 170+180+180+388, 81);
				MoveToEx(hdc, 170+180+180+350, 91, NULL); LineTo(hdc, 170+180+180+388, 87);
				///Right
				MoveToEx(hdc, 170+180+180+440, 68, NULL); 	LineTo(hdc, 170+180+180+402, 74);
				MoveToEx(hdc, 170+180+180+442, 79, NULL); 	LineTo(hdc, 170+180+180+402, 81);
				MoveToEx(hdc, 170+180+180+440, 91, NULL); 	LineTo(hdc, 170+180+180+402, 87);
				//Lip
				SelectObject(hdc,CreateSolidBrush(RGB(255,70,0)));
				Chord(hdc,170+180+180+355,35,170+180+180+435,125,170+180+180+200,182,170+180+180+602,184);
      			//Neck
				SelectObject(hdc,CreatePen(PS_DASH, 10, RGB(255,0,0)));
				MoveToEx(hdc, 170+180+180+365, 138, NULL);
				LineTo(hdc, 170+180+180+425, 138);
				//Ring
				SelectObject(hdc,CreatePen(PS_SOLID, 1, RGB(0,0,0)));
				SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
				Ellipse (hdc, 170+180+180+388, 145, 170+180+180+403, 130);



				EndPaint (hwnd, &ps);
				return 0;


			case WM_DESTROY:
					PostQuitMessage (0);
					return 0;
			}
			return DefWindowProc (hwnd, message, wParam, lParam);
}
