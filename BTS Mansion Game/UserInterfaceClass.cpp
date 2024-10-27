#include "UserInterfaceClass.h"
#include <iostream>

UserInterfaceClass::UserInterfaceClass()
{
    current_input = "";
}
void UserInterfaceClass::displayPrompt(const std::string& prompt) const
{
	std::cout << prompt << std::endl; //prints strng passed
}
void UserInterfaceClass::displayMenu() const
{
	std::cout << "***Welcome to the BTS Mansion Game!***" << std::endl; //No title yet, change in future and adjust for story building etc etc
    std::cout << "===== Main Menu =====" << std::endl;
    std::cout << "START Game" << std::endl;
    std::cout << "QUIT" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "Words in all caps will be input options for this game, please enter an option: ";
}

void UserInterfaceClass::setCurrentInput(std::string& uInput)
{
    UserInterfaceClass::current_input = uInput; //set passed string to current input private member variable
}

std::string UserInterfaceClass::getCurrentInput() const
{
    return current_input; //returns string of current input private member variable
}

std::string UserInterfaceClass::userInput() 
{
    std::string input;
    std::getline(std::cin, input);
    this->setCurrentInput(input); //sets current input to this
    return input;
}

void UserInterfaceClass::waitForInput() const {
    std::string input;
    while (true) 
    {
        std::getline(std::cin, input);
        if (input.empty())
        {
            break;
        }
        else if (input == "PICKUP")
        {
            break;
        }
        else 
        {
            std::cout << "Invalid input, please press Enter key to continue story\n";
        }
      
       
        
    }
}

bool UserInterfaceClass::isValidInput(const std::string[]) const
{
    //TODO: add logic
    return true;
}

void UserInterfaceClass::displayPentacle(int candleVal)
{
    if (candleVal == 0) {
        std::cout << R"(   
       ".d$$$******$$$$c."        
    ".d$P'            '$$c"      
   "$$$$$.           .$$$*$."    
 ".$$ 4$L*$$.     .$$Pd$  '$b"   
 "$F   *$. '$$e.e$$' 4$F   ^$b"  
"d$     $$   z$$$e   $$     '$." 
"$P     `$L$$P` `'$$d$'      $$" 
"$$     e$$F       4$$b.     $$" 
"$b  .$$' $$      .$$ '4$b.  $$" 
"$$e$P    $b     d$`    $$c$F" 
"$P$$$$$$$$$$$$$$$$$$$$$$$$$$"  
 "'$c.      4$.  $$       .$$"   
  "^$$.      $$ d$'      d$P"    
    "'$$c.   `$b$F    .d$P'"     
      "`4$$$c.$$$..e$$P'"        
          "`^^^^^^^`';")" << std::endl;

    }
    else if (candleVal == 1) {
        std::cout << R"(   
       ".d$$$******$$$$c."        
    ".d$P'            '$$c"      
   "$$$$$.           .$$$*$."    
 ".$$ 4$L*$$.     .$$Pd$  '$b"   
 "$F   *$. '$$e.e$$' 4$F   ^$b"  
"d$     $$   z$$$e   $$     '$." 
"$P     `$L$$P` `'$$d$'      $$" 
"$$     e$$F       4$$b.     $$" 
"$b  .$$' $$      .$$ '4$b.  $$" 
"$$e$P    $b     d$`    $$c$F" 
"$P$$$$$$$$$$$$$$$$$$$$$$$$$$"  
 "'$c.      4$.  $$       .$$"   
  "^$$.      $$ d$'      d$P"    
    "'$$c.   `$b$F    .d$P'"     
      "`4$$$c/||||\e$$P'"        
          "`^\||||/`';")" << std::endl;

    }
    else if (candleVal == 2) {
        std::cout << R"(   
       ".d$$$******$$$$c."        
    ".d$P'            '$$c"      
   "$$$$$.           .$$$*$."    
 ".$$ 4$L*$$.     .$$Pd$  '$b"   
 "$F   *$. '$$e.e$$' 4$F   ^$b"  
"d$     $$   z$$$e   $$     '$." 
"$P     `$L$$P` `'$$d$'      $$" 
"$$     e$$F       4$$b.     $$" 
"$b  .$$' $$      .$$ '4$b.  $$" 
"$$e$P    $b     d$`    $$c$/||\
"$P$$$$$$$$$$$$$$$$$$$$$$$$$\||/  
 "'$c.      4$.  $$       .$$"   
  "^$$.      $$ d$'      d$P"    
    "'$$c.   `$b$F    .d$P'"     
      "`4$$$c/||||\e$$P'"        
          "`^\||||/`';")" << std::endl;

    }
    else if (candleVal == 3) {
        std::cout << R"(   
       ".d$$$******$$$$c."        
    ".d$P'            '$$c"      
   "$$$$$.           .$$$*$."    
 ".$$ 4$L*$$.     .$$Pd$  '$b"   
 "$F   *$. '$$e.e$$' 4$F   ^$b"  
"d$     $$   z$$$e   $$     '$." 
"$P     `$L$$P` `'$$d$'      $$" 
"$$     e$$F       4$$b.     $$" 
"$b  .$$' $$      .$$ '4$b.  $$" 
/||\-$P    $b     d$`    $$c/||\
\||/$$$$$$$$$$$$$$$$$$$$$$$$\||/  
 "'$c.      4$.  $$       .$$"   
  "^$$.      $$ d$'      d$P"    
    "'$$c.   `$b$F    .d$P'"     
      "`4$$$c/||||\e$$P'"        
          "`^\||||/`';")" << std::endl;

    }
    else {
        /* place holder for when we add the last 2 candles*/
        std::cout << R"(bruh   
       ".d$$$******$$$$c."        
    ".d$P'            '$$c"      
   "$$$$$.           .$$$*$."    
 ".$$ 4$L*$$.     .$$Pd$  '$b"   
 "$F   *$. '$$e.e$$' 4$F   ^$b"  
"d$     $$   z$$$e   $$     '$." 
"$P     `$L$$P` `'$$d$'      $$" 
"$$     e$$F       4$$b.     $$" 
"$b  .$$' $$      .$$ '4$b.  $$" 
"$$e$P    $b     d$`    $$c$F" 
"$P$$$$$$$$$$$$$$$$$$$$$$$$$$"  
 "'$c.      4$.  $$       .$$"   
  "^$$.      $$ d$'      d$P"    
    "'$$c.   `$b$F    .d$P'"     
      "`4$$$c.$$$..e$$P'"        
          "`^^^^^^^`';")" << std::endl;

    }

}
