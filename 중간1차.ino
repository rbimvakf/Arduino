byte digits[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1}
};

int number = 0;
bool isRunning = false;

void setup() {
  for(int i=2; i<9; i++)
    pinMode(i, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  if(digitalRead(13) == HIGH) // #2
    number = 0;
  
  displayNum(number);

  if(digitalRead(12) == HIGH) // #1
    isRunning = true;
  else
    isRunning = false;

  if(isRunning) {
    number++;
    delay(1000);
    if(number > 9)
      number = 0;
  }
}

void displayNum(int a) {
  for(int i=0; i<7; i++) digitalWrite(i+2, digits[a][i]);
}
