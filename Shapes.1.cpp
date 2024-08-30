// Assignment 2, Shapes v.1

// Program will read from text file and specify one shape object or
// be blank. Program will calculate area, perimeter, volume, and surface
// area of various shapes, then output into two different sources.

// c++ libraries
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// c libraries
#include <cstdlib>   // atof
#include <cmath>     // sqrt and M_PI

// function prototypes
void id();
vector<string> parseString(string);

int main()
{
  // function call for identification information
  id();

  // declare and initialize variables
  ifstream fin;     
  ofstream fout; 
  string line;
  double length = 0.0;
  double width = 0.0;
  double height = 0.0;
  double radius = 0.0;
  double calc1 = 0.0;       // used for area and surface area
  double calc2 = 0.0;       // used for perimeter and volume
  vector<string> tokens;   

  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  // Check if input file is opened successfully
  if (!fin.good())
  {
    cout << "Input file failed to open." << endl;
    return 1;
  }
 
  // Check if output file is opened successfully
  if (!fout.good())
  {
    cout << "Output file failed to open." << endl;
    return 1;
  }

  // keep looping until end of file is reached
  while (!fin.eof())
  {
    // read each line from input file and call function to get tokens
    getline(fin, line);
    tokens = parseString(line);

    // will skip any empty lines from input file
    if (tokens.size() != 0)
    { 
      // check if token is square
      if (tokens[0] == "SQUARE") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;

        // calculate area and perimeter
        calc1 = length * length;
        calc2 = 4 * length;

        // display results to console
        cout << tokens[0] << " side=" << length;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " side=" << length;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }

      // check if token is rectangle
      else if (tokens[0] == "RECTANGLE") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        width = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
        
        // calculate area and perimeter
        calc1 = length * width;
        calc2 = 2 * (length + width);

        // display results to console
        cout << tokens[0] << " length=" << length << " width=" << width;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " length=" << length << " width=" << width;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6); 
      }

      // check if token is circle
      else if (tokens[0] == "CIRCLE") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        radius = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        
        // calculate area and perimeter
        calc1 = M_PI * radius * radius;
        calc2 = 2 * M_PI * radius;

        // display results to console
        cout << tokens[0] << " radius=" << radius;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " radius=" << radius;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }

      // check if token is triangle
      else if (tokens[0] == "TRIANGLE") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        
        // calculate area and perimeter
        calc1 = (sqrt(3) / 4) * length * length;
        calc2 = 3 * length;

        // display results to console
        cout << tokens[0] << " side=" << length;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " side=" << length;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << calc1 << " perimeter=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      } 
      
      // check if token is cube
      else if (tokens[0] == "CUBE") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;

        // calculate surface area and volume
        calc1 = 6 * length * length;
        calc2 = length * length * length;

        // display results to console
        cout << tokens[0] << " side=" << length;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " side=" << length;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      } 

      // check if token is box           
      else if (tokens[0] == "BOX") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        width = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
        height = (tokens.size() > 3) ? atof(tokens[3].c_str()) : 0;

        // calculate surface area and volume
        calc1 = 2 * ((length * width) + (width * height) + (length * height));
        calc2 = length * width * height;

        // display results to console
        cout << tokens[0] << " length=" << length << " width=" << width << " height=" << height;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);    

        // write results to output file
        fout << tokens[0] << " length=" << length << " width=" << width << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      } 

      // check if token is cylinder      
      else if (tokens[0] == "CYLINDER") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0 
        radius = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        height = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
  
        // calculate surface area and volume
        calc1 = (2 * M_PI * radius * radius) + (2 * M_PI * radius * height);
        calc2 = M_PI * radius * radius * height;

        // display results to console
        cout << tokens[0] << " radius=" << radius << " height=" << height;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " radius=" << radius << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      
      // check if token is prism
      else if (tokens[0] == "PRISM") 
      {
        // check if enough tokens for sides
        // if not, assign the side with 0
        length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        height = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;

        // calculate surface area and volume
        calc1 = ((sqrt(3) / 2) * length * length) + (3 * length * height);
        calc2 = (sqrt(3) / 4) * length * length * height;

        // display results to console
        cout << tokens[0] << " side=" << length << " height=" << height;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        cout.unsetf(ios::fixed);
        cout.precision(6);

        // write results to output file
        fout << tokens[0] << " side=" << length << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << calc1 << " volume=" << calc2 << endl;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }

      // check if token is EOF      
      else if (tokens[0] == "EOF")
        break;

      // token does not match one of eight objects
      else
        cout << tokens[0] << " invalid object" << endl;
    }
  }

  fin.close();
  fout.close();

  return 0;
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will take a string and create an array of tokens
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

