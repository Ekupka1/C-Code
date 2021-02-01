// Ethan Kupka Final C Coding Project Work in Progress-- Cache

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// stores the size as 4 GB
struct size{
  int value;
  char unit[5];
};

// stores the memory, block, and cache size
struct memoryInfo{
  struct size memorySize;
  struct size cacheSize;
  struct size blockSize;
};

// stores the tag length and line num length and wordLength in bits
struct addressFormat{
  int wordLength;
  int lineNumLength;
  int tagLength;
};

// stores actual value of tag and true/flase of the data
struct cacheLine{
  int tag;
  int isValid;
};

          //--- Start of Functions

// function 1: Random generator it takes a max address and generates an address between 0 to max address-1.
int generateAddress(int memorySize){
  return rand()%memorySize;
}

// function 2: Gets the size of either RAM, cache or memory block.
struct size getSize(char* message){
    struct size sizeVariable;
    printf("%s", message);
    scanf("%d%s",&(sizeVariable.value), sizeVariable.unit);
    return sizeVariable;
}

// function 3: Returns the tag of the address from the addressFormat
int getSetTag(int address, struct addressFormat formatAddress){
  int tag = 0;
  address = address >> 4;
  tag = address&&(pow(2,2)-1);

  return tag;
}

// function 4: Returns a set number of the address from the addressFormat
int getSetNum(int address, struct addressFormat formatAddress){
  int lineNum = 0;
  address = address >> 2;
  lineNum = address&&(pow(2,2)-1);

  return lineNum;
}

// function 5: obtains address seeing if its a hit or miss thrugh true and flase (1 or 0)
int missOrHit(int lineNum, int tag, struct cacheLine* cache){
    int cacheHit = 0;
    //int lineNum = 0;
    int A[tag];
    for (lineNum = 0; lineNum < tag; lineNum += 128) {
        A[tag] = lineNum;

    } /* Line 1 */
      for (lineNum = 0; lineNum < tag; lineNum += 128) {
        cacheHit += A[tag];
      } /* Line 2 */
      return (cache[lineNum].isValid==1 && cache[lineNum].tag == tag);

}

/*// function 6: Gets the tag and line#, and updates the cache
void updateCache(int lineline, int tag, struct cacheLine* cache){

}
*/

 // function 7: Calc the power of the bits choosen of the string (%s)
int calcPower(struct size cacheOrMemorySize){
    int numOfBits = log2(cacheOrMemorySize.value);
    if(strcmp(cacheOrMemorySize.unit,"KB")==0)
      numOfBits += 10;
    else if(strcmp(cacheOrMemorySize.unit,"MB")==0)
      numOfBits += 20;
    else if(strcmp(cacheOrMemorySize.unit, "GB")==0)
      numOfBits += 30;
    return numOfBits;
}
          //---End of functions

//Start of main asking for the address MM, BS, and CS
int main(){

  /*
   * Get the RAM, cache and block sizes from user
  */
    printf("Selcect a number thats a power of 2 along with the size (GB, MB, KB) in ALL CAPS (EX: 8GB)\n"); // ex should be power of two while
    struct size memorySize = getSize("Enter RAM size: ");
    struct size blockSize = getSize("Enter block size: ");
    struct size cacheSize = getSize("Enter cache size: ");

    /*
     * Calculate the address format based on the RAM, block, and cache sizes.
    */
    int addressLength = calcPower(memorySize);
    int wordLength = calcPower(blockSize);
    int cacheLength = calcPower(cacheSize);
    struct addressFormat formatAddress;
    formatAddress.wordLength = wordLength;
    formatAddress.lineNumLength = cacheLength - wordLength;
    formatAddress.tagLength = addressLength - wordLength - formatAddress.lineNumLength;

    /*
     * Creating and initializing cache.
    */
    printf("\n");
    int numberOfLines = (int) pow(2, cacheLength - wordLength);
    struct cacheLine cache[numberOfLines];
    for(int line =0; line < numberOfLines; line++){
      cache[line].isValid = 0;
    } // End of for loop

    /*
     * Ask or # of Reads
    */
    int numReads;
    printf("Enter many 'reads' would you like form this program: ");
    scanf("%d",&numReads);
    int hitCount = 0;
    int missCount = 0; // Dont really need

    for(int read=0; read<numReads; read++){
        //step 1: Generate address
        int address = generateAddress((int)pow(2, addressLength));
        //setp 2: separate tag and line number
        int tag = getSetTag(address, formatAddress);
        int lineNum = getSetNum(address, formatAddress);
        //step 3: check if the cache[line] has the same tag
        //        and if the valid field is 1
        //step 4: if cachehit => hitCount = hitCount+1
        int hitCount = missOrHit( lineNum, tag, cache);
        if (int cacheHit=0; hitCount<= cacheHit; cacheHit++ ) {
          hitCount = hitCount+1;
          return hitCount;
          }
        else {
          missCount = missCount+1;
          return missCount;
        }
        //step 5: if cache miss => bring the block into the cache line
        //        copy the tag of the address int cache[line].address
        //        set valid field to 1.
    } // End of for

    /*
     * Prints missOrHit and Reads along with finding the hit ratio
    */
    printf("HIT Count is: %d\nNumber of 'reads' is: %d\n", *(int*)missOrHit, numReads);
    float hitRatio (float hitCount, float numReads){
        return hitCount/numReads;
    } // End of float ratio
    printf("HIT ratio is: %f\n", *(float*)hitRatio);

    return 0;
} //-End of main
