//********************** SETUP **********************
#include<Wire.h>
#include<SD.h>

int input_pattern_int[300];
void setup()
{
  SD.begin();
    
  Wire.begin(1);
  
}
File pattern_file = SD.open("patterns.txt");

//****************** START LOOPING ******************
void loop()
{

  //******** UPLOADING PATTERNS *********
  if (pattern_file)
  {
    for(int i=0;i<300;i++)
    {
      input_pattern_int[i]=pattern_file.parseInt();
    }
    pattern_file.close();
    
  }
  //********** PATTERN WRITING **********
  
  //*********** START SIGNAL ************
}

//***************** KUNG-FU NCTIONS *****************

//********* PATTERN PARSING ************

void parse_input_pattern(String input_pattern)
{
  int reverse_input_pattern[300],array_index_counter=0,power=0;
  for(int i=0; i<300;i++) reverse_input_pattern[i]=0;
  for(int i = input_pattern.length(); i>=0; i--)
  {
    if(input_pattern[i]<=49 && input_pattern[i]>=58)
    {
      reverse_input_pattern[array_index_counter]+=(input_pattern[i]-49)*pow(10,power);
      power++;
    }
    else
    {
      power=0;
      array_index_counter++;
    }
  }
  for(int i=0;i<300;i++)  input_pattern_int[i]=reverse_input_pattern[299-i];
}
