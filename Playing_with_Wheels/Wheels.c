#include <stdio.h>
#include <stdbool.h>

int* denumber(int x) {

  /* Variables */
  static int numbers[4];
  int i;

  for(i = 0; i < 4; i++) {
    numbers[3 - i] = x % 10;
    x /= 10;
  }

  return numbers;
}

int inumber() {

  /* Variables */
  int digit, j, number = 0;
  
  for(j = 0; j < 4; j++) {
    scanf("%d", &digit);
    number = number + digit * ipow(10, 3 - j);
  }

  return number;
}

int ipow(int i, int j) {

  /* Variables */
  int result = 1;

  while(j > 0) {
    result = result * i;
    j--;
  }

  return result;
}

int absNumber(int x) {
  if(x < 0)
    return x * -1;
  return x;
}

int MannDistance(int x, int y) {

  /* Variables */
  int i, sum = 0;
  
  for(i = 0; i < 4; i++) {
    int powNumber = ipow(10, 3 - i);
    sum += absNumber((x / powNumber - y / powNumber));
    x %= powNumber;
    y %= powNumber;
  }
  return sum;
}

int checking(int* data) {

  /* Variables */
  int start = data[0];
  int goal = data[1];
  int avoid[10000], currentArray[10000], previousArray[10000];
  int avoidSize = data[2], currentArraySize = 1, previousArraySize = 1;
  int i, j, x, steps = 0;
  int currentNumber;
  int currentNumbers[8];
  int currentNumberSize;
  int currentArrayCount;
  int currentMannDistance = MannDistance(start, goal);
  int nowMannDistance = 0;
  bool isThere;

  for(i = 0; i < data[2]; i++) {
    avoid[i] = data[3 + i];
  }

  currentArray[0] = start;

  while(currentArraySize != 0) {

    currentArrayCount = 0;
    for(i = 0; i < currentArraySize; i++) {
      previousArray[i] = currentArray[i];
      if(currentArray[i] == goal)
	return steps;
    }

    previousArraySize = currentArraySize;

    for(i = 0; i < previousArraySize; i++) {

      currentNumber = previousArray[i];
      currentNumberSize = 0;

      if(currentNumber >= 9000)
	currentNumbers[0] = currentNumber % 1000;
      else
	currentNumbers[0] = currentNumber + 1000;
      
      if(currentNumber < 1000)
	currentNumbers[1] = currentNumber + 9000;
      else
	currentNumbers[1] = currentNumber - 1000;

      if((currentNumber % 1000) >= 900)
	currentNumbers[2] = currentNumber - 900;
      else
	currentNumbers[2] = currentNumber + 100;
      
      if((currentNumber % 1000) < 100)
	currentNumbers[3] = currentNumber + 900;
      else
	currentNumbers[3] = currentNumber - 100;

      if((currentNumber % 100) >= 90)
	currentNumbers[4] = currentNumber - 90;
      else
	currentNumbers[4] = currentNumber + 10;
      
      if((currentNumber % 100) < 10)
	currentNumbers[5] = currentNumber + 90;
      else
	currentNumbers[5] = currentNumber - 10;

      if((currentNumber % 10) >= 9)
	currentNumbers[6] = currentNumber - 9;
      else
	currentNumbers[6] = currentNumber + 1;
      
      if((currentNumber % 10) < 1)
	currentNumbers[7] = currentNumber + 9;
      else
	currentNumbers[7] = currentNumber - 1;
      
      for(x = 0; x < 8; x++) {
	nowMannDistance = MannDistance(currentNumbers[x], goal);
	if(nowMannDistance == 0) {
	  return steps + 1;
	}
	if(nowMannDistance <= currentMannDistance + 3) {
	  currentNumbers[currentNumberSize] = currentNumbers[x];
	  currentNumberSize++;
	  currentMannDistance = nowMannDistance;
	}
      }

      for(x = 0; x < currentNumberSize; x++) {
	isThere = true;
	for(j = 0; j < avoidSize; j++) {
	  if(currentNumbers[x] == avoid[j]) {
	    isThere = false;
	    break;
	  }
	}
	if(isThere) {
	  currentArray[currentArrayCount] = currentNumbers[x];
	  avoid[avoidSize] = currentNumbers[x];
	  avoidSize++;
	  currentArrayCount++;
	}
      }
    }
    currentArraySize = currentArrayCount;
    steps++;

  }

  return -1;
}

int main() {

  /* Variables */
  int numberOfCase = 0, numberOfAvoid = 0;
  int i, j;

  scanf("%d", &numberOfCase);

  /*Data*/
  int data[10050];
  int result[numberOfCase];
  
  for(i = 0; i < numberOfCase; i++) {
    for(j = 0; j < 2; j++) {
      data[j] = inumber();
    }

    scanf("%d", &numberOfAvoid);
    data[2] = numberOfAvoid;
    for(j = 3; j < numberOfAvoid + 3; j++) {
      data[j] = inumber();
    }
    result[i] = checking(data);
  }

  for(i = 0; i < numberOfCase; i++) {
    printf("%d\n", result[i]);
  }

  return 0;
}
