#include <stdio.h>
#include <stdlib.h>
#define MAX_ROOMS 5
void initializeSystem(int numRooms, int lights[], int locks[], int motion[], int temps[]);
void displayMenu();
void controlLights(int numRooms, int lights[]);
void readTemperature(int numRooms, int temps[]);
void detectMotion(int numRooms, int motion[]);
void securitySystem(int numRooms, int locks[]);
void analyzeHouseStatus(int numRooms, int lights[], int locks[], int motion[], int temps[]);

int main() {
    int numRooms;
    printf("Enter number of rooms (max %d): ", MAX_ROOMS);
    scanf("%d", &numRooms);

    if (numRooms <= 0 || numRooms > MAX_ROOMS) {
        printf("Invalid number of rooms. Exiting program.\n");
        return 1;
    }
    int lights[numRooms];  
    int locks[numRooms];   
    int motion[numRooms];  
    int temps[numRooms];   

    initializeSystem(numRooms, lights, locks, motion, temps);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(numRooms, lights);
                break;
            case 2:
                readTemperature(numRooms, temps);
                break;
            case 3:
                detectMotion(numRooms, motion);
                break;
            case 4:
                securitySystem(numRooms, locks);
                break;
            case 5:
                analyzeHouseStatus(numRooms, lights, locks, motion, temps);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeSystem(int numRooms, int lights[], int locks[], int motion[], int temps[]) {
    for (int i = 0; i < numRooms; i++) {
        lights[i] = 0;      
        locks[i] = 1;      
        motion[i] = 0;      
        temps[i] = 22;      
    }
    printf("System initialized. All devices are set to default states.\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int numRooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

void readTemperature(int numRooms, int temps[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    printf("Temperature in Room %d: %d°C\n", room, temps[room - 1]);
}

void detectMotion(int numRooms, int motion[]) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
}

void securitySystem(int numRooms, int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    locks[room - 1] = !locks[room - 1];
    printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
}

void analyzeHouseStatus(int numRooms, int lights[], int locks[], int motion[], int temps[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
            i + 1, 
            lights[i] ? "ON" : "OFF", 
            temps[i], 
            motion[i] ? "Motion Detected" : "No Motion", 
            locks[i] ? "Locked" : "Unlocked");
    }
}
