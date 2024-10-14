#include <math.h>
#include <stdio.h>
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
void usleep(__int64 usec)
{
  HANDLE timer;
  LARGE_INTEGER ft;

  ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

  timer = CreateWaitableTimer(NULL, TRUE, NULL);
  SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
  WaitForSingleObject(timer, INFINITE);
  CloseHandle(timer);
}
#endif

// Rotational angles
float A = 0, B = 0, C = 0;

// Cube dimensions and screen properties
float cubeWidth;
int width = 160, height = 44;

// Z-buffer and output character buffer
float zBuffer[160 * 44];
char buffer[160 * 44];

// Background character for empty space
int backgroundASCIICode = '.';

// Camera properties
int distanceFromCam = 100;
float horizontalOffset;
float K1 = 40;

// Increment speed for cube animation
float incrementSpeed = 0.6;

// Variables for transformed coordinates
float x, y, z;
float ooz; // One over z (used for depth perspective)
int xp, yp;
int idx;

// Function to calculate transformed X coordinate based on rotation angles
float calculateX(int i, int j, int k) {
  return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
         j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

// Function to calculate transformed Y coordinate based on rotation angles
float calculateY(int i, int j, int k) {
  return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
         j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
         i * cos(B) * sin(C);
}

// Function to calculate transformed Z coordinate based on rotation angles
float calculateZ(int i, int j, int k) {
  return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

// Function to calculate screen positions and update buffers for a given cube surface point
void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
  // Apply rotation transformations
  x = calculateX(cubeX, cubeY, cubeZ);
  y = calculateY(cubeX, cubeY, cubeZ);
  z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

  // Calculate 1/z for depth perspective
  ooz = 1 / z;

  // Project the 3D coordinates to 2D screen space
  xp = (int)(width / 2 + horizontalOffset + K1 * ooz * x * 2);
  yp = (int)(height / 2 + K1 * ooz * y);

  // Calculate the index in the buffer
  idx = xp + yp * width;

  // Update buffers if the current point is closer to the viewer
  if (idx >= 0 && idx < width * height) {
    if (ooz > zBuffer[idx]) {
      zBuffer[idx] = ooz;
      buffer[idx] = ch;
    }
  }
}

int main() {
  // Clear the screen
  printf("\x1b[2J");
  while (1) {
    // Reset the buffers
    memset(buffer, backgroundASCIICode, width * height);
    memset(zBuffer, 0, width * height * sizeof(float));

    // Draw multiple cubes with different sizes and offsets
    // First Cube
    cubeWidth = 20;
    horizontalOffset = -2 * cubeWidth;
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

    // Second Cube (smaller and offset to the right)
    cubeWidth = 10;
    horizontalOffset = 1 * cubeWidth;
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

    // Third Cube (even smaller and further right)
    cubeWidth = 5;
    horizontalOffset = 8 * cubeWidth;
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

    // Move the cursor to the top-left corner
    printf("\x1b[H");

    // Render the frame by printing the buffer to the console
    for (int k = 0; k < width * height; k++) {
      putchar(k % width ? buffer[k] : '\n');
    }

    // Update rotation angles for the next frame to animate the cubes
    A += 0.05;
    B += 0.05;
    C += 0.01;

    // Pause to control frame rate
    usleep(8000 * 2);
  }
  return 0;
}
