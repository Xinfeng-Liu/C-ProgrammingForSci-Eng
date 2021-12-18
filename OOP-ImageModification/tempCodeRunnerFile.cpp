mainChoice = printMainMenue();
        if(mainChoice == CHOICE_MIN){
            //choice 1: add rectangle
            int methodChoice;
            int rowStart; 
            int colStart;
            int rowEnd; 
            int colEnd;
            bool validSetup = false;
            cout << RECT_FIST_POSITION;
            cout << ". Specify upper left and ";
            cout << "lower right corners of rectangle" << endl;
            cout << RECT_SECOND_POSITION;
            cout << ". Specify upper left corner and ";
            cout << "dimensions of rectangle" << endl;
            cout << RECT_THIRD_POSITION;
            cout << ". Specify extent from center of rectangle";
            cout << endl;
            cout << "Enter int for rectangle specification method: ";
            cin >> methodChoice;
            //check if input is valid
            if(cin.fail() || !isInputValid(methodChoice,
                                            CHOICE_MIN, 
        