#include <SFML/Graphics.hpp>
using namespace sf;
#include "Graph.h"
#include "Algorithms.h"
#include "FileHandler.h"
#include <cmath>

void runGUI(Graph& g){

    string currentScreen = "main";
    
        RenderWindow window(
            VideoMode({1000,880}),
            "Social Network Friend Recommendation System"
        );

        Algorithms algo; //creating object 
        FileHandler fh;
        string statusMessage="";
        string activeInput="";
        string recommendationData="";
        string bfsData = "";
        string graphInput = "";
        int selectedGraphUser = -1;

        //loading font from folder
        Font font("HandsonBold-9Mnrl.otf");
        
        //Creating buttons (objects)
        RectangleShape AddUser({270,60});
        RectangleShape AddFriendship({270,60});
        RectangleShape ShowNetwork({270,60});
        RectangleShape RecommendFriends({270,60});
        RectangleShape BFStraversal({270,60});
        RectangleShape Exit({270,60}); 
        RectangleShape Submit({270,60});  //add friendship
        RectangleShape Back({270,60});    //add friendship
        RectangleShape Submit2({270,60});    //add user
        RectangleShape submitfri({270,60});  //friend recommendation


        // BUTTON COLORS
        AddUser.setFillColor(Color(90,150,200));
        AddFriendship.setFillColor(Color(90,150,200));
        ShowNetwork.setFillColor(Color(90,150,200));
        RecommendFriends.setFillColor(Color(90,150,200));
        BFStraversal.setFillColor(Color(90,150,200));
        Exit.setFillColor(Color(90,150,200));
        Submit.setFillColor(Color(90,150,200));
        Back.setFillColor(Color(90,150,200));
        Submit2.setFillColor(Color(90,150,200));
        submitfri.setFillColor(Color(90,150,200));
    
        //Button positions
        AddUser.setPosition({350,250});
        AddFriendship.setPosition({350,350});
        ShowNetwork.setPosition({350,450});
        RecommendFriends.setPosition({350,550});
        BFStraversal.setPosition({350,650});
        Exit.setPosition({350,750});
        Submit.setPosition({350,500});
        Back.setPosition({350,610});
        Submit2.setPosition({360,790});

        //text
        Text addUsertxt(font);
        Text friendtxt(font);
        Text showtxt(font);
        Text recommendtxt(font);
        Text bfstxt(font);
        Text exittxt(font);
        Text text1(font);
        Text text2(font);
        Text friendtitle(font);   //add friendship
        Text user1(font);        //add friendship
        Text user2(font);        //add friendship
        Text submittxt(font);    //add friendship
        Text backtxt(font);      //add friendship
        Text statusText(font);   //add friendship
        Text usertxt(font);      //add user
        Text statustext2(font);  //add user

        text1.setString("Welcome!");
        text2.setString("Discover | Connect | Grow");
        addUsertxt.setString("Add User");
        friendtxt.setString("Add Friendship");
        showtxt.setString("Show Network");
        recommendtxt.setString("Recommend Friends");
        bfstxt.setString("BFS Traversal");
        exittxt.setString("Graph");
        friendtitle.setString("Add Friendship");  
        user1.setString("Enter User ID 1 ");      
        user2.setString("Enter User ID 2 ");        
        submittxt.setString("SUBMIT");
        backtxt.setString("BACK");             
        usertxt.setString("Add New User");   //add user


        //text size
        text1.setCharacterSize(70);
        text2.setCharacterSize(55);
        addUsertxt.setCharacterSize(33);
        friendtxt.setCharacterSize(33);
        showtxt.setCharacterSize(33);
        recommendtxt.setCharacterSize(33);
        bfstxt.setCharacterSize(33);
        exittxt.setCharacterSize(33);
        friendtitle.setCharacterSize(90);
        user1.setCharacterSize(37);
        user2.setCharacterSize(37);
        submittxt.setCharacterSize(37);
        backtxt.setCharacterSize(37);
        statusText.setCharacterSize(37);
        usertxt.setCharacterSize(50);
        statustext2.setCharacterSize(30);

        // text color
        text1.setFillColor(Color(80,60,100));
        text2.setFillColor(Color(80,60,100));
        addUsertxt.setFillColor(Color(130, 100, 160)); //white
        friendtxt.setFillColor(Color(130, 100, 160));
        showtxt.setFillColor(Color(130, 100, 160));
        recommendtxt.setFillColor(Color(130, 100, 160));
        bfstxt.setFillColor(Color(130, 100, 160));
        exittxt.setFillColor(Color(130, 100, 160));
        friendtitle.setFillColor(Color(130, 100, 160));
        user1.setFillColor(Color(80,60,100));
        user2.setFillColor(Color(80,60,100));
        submittxt.setFillColor(Color(130, 100, 160));
        backtxt.setFillColor(Color(130, 100, 160));
        statusText.setFillColor(Color(80,60,100));
        usertxt.setFillColor(Color(80,60,100));
        statustext2.setFillColor(Color(80,60,100));


        // text position
        text1.setPosition({380,50});
        text2.setPosition({275,150});
        addUsertxt.setPosition({433,261});
        friendtxt.setPosition({400,361});
        showtxt.setPosition({407,461});
        recommendtxt.setPosition({387,561});
        bfstxt.setPosition({414,661});
        exittxt.setPosition({440,755});
        friendtitle.setPosition({300,50});
        user1.setPosition({390,200});
        user2.setPosition({390,345});
        submittxt.setPosition({440,510});
        backtxt.setPosition({450,614});
        statusText.setPosition({250,780});
        usertxt.setPosition({375,7});
        statustext2.setPosition({20,840});



        // for Add friendship 
        //input 1
        string input1="";
        RectangleShape inputbox1({270,60});
        inputbox1.setPosition({350,250});
        inputbox1.setFillColor(Color::White);
        inputbox1.setOutlineThickness(2);
        inputbox1.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay1(font);
        inputdisplay1.setCharacterSize(49);
        inputdisplay1.setFillColor(Color(90,150,200));
        inputdisplay1.setPosition({470,248});
        //input 2 for Add friendship
        string input2="";
        RectangleShape inputbox2({270,60});
        inputbox2.setPosition({350,393});
        inputbox2.setFillColor(Color::White);
        inputbox2.setOutlineThickness(2);
        inputbox2.setOutlineColor(Color(150,150,150));
        //output 2
        Text inputdisplay2(font);
        inputdisplay2.setCharacterSize(49);
        inputdisplay2.setFillColor(Color(90,150,200));
        inputdisplay2.setPosition({470,385});

        //for add user

        //text1
        Text userid(font);
        userid.setString("Enter User ID "); 
        userid.setCharacterSize(33);
        userid.setFillColor(Color(80,60,100));
        userid.setPosition({410,79});
        //input 1
        string input3="";
        RectangleShape inputbox3({270,50});
        inputbox3.setPosition({360,120});
        inputbox3.setFillColor(Color::White);
        inputbox3.setOutlineThickness(2);
        inputbox3.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay3(font);
        inputdisplay3.setCharacterSize(49);
        inputdisplay3.setFillColor(Color(90,150,200));
        inputdisplay3.setPosition({470,110});

        //text2
        Text username(font);
        username.setString("Enter Name "); 
        username.setCharacterSize(33);
        username.setFillColor(Color(80,60,100));
        username.setPosition({419,180});
        //input 1
        string input4="";
        RectangleShape inputbox4({270,50});
        inputbox4.setPosition({360,220});
        inputbox4.setFillColor(Color::White);
        inputbox4.setOutlineThickness(2);
        inputbox4.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay4(font);
        inputdisplay4.setCharacterSize(49);
        inputdisplay4.setFillColor(Color(90,150,200));
        inputdisplay4.setPosition({410,215});

         //text3
        Text gender(font);
        gender.setString("Enter Gender "); 
        gender.setCharacterSize(33);
        gender.setFillColor(Color(80,60,100));
        gender.setPosition({420,280});
        //input 1
        string input5="";
        RectangleShape inputbox5({270,50});
        inputbox5.setPosition({360,320});
        inputbox5.setFillColor(Color::White);
        inputbox5.setOutlineThickness(2);
        inputbox5.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay5(font);
        inputdisplay5.setCharacterSize(49);
        inputdisplay5.setFillColor(Color(90,150,200));
        inputdisplay5.setPosition({438,315});

        //text4
        Text DOB(font);
        DOB.setString("Enter Date of Birth "); 
        DOB.setCharacterSize(33);
        DOB.setFillColor(Color(80,60,100));
        DOB.setPosition({390,380});
        //input 1
        string input6="";
        RectangleShape inputbox6({270,50});
        inputbox6.setPosition({360,420});
        inputbox6.setFillColor(Color::White);
        inputbox6.setOutlineThickness(2);
        inputbox6.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay6(font);
        inputdisplay6.setCharacterSize(49);
        inputdisplay6.setFillColor(Color(90,150,200));
        inputdisplay6.setPosition({410,415});

        //text5
        Text city(font);
        city.setString("Enter City "); 
        city.setCharacterSize(33);
        city.setFillColor(Color(80,60,100));
        city.setPosition({418,580});
        //input 1
        string input7="";
        RectangleShape inputbox7({270,50});
        inputbox7.setPosition({360,620});
        inputbox7.setFillColor(Color::White);
        inputbox7.setOutlineThickness(2);
        inputbox7.setOutlineColor(Color(150,150,150));
        //output 2
        Text inputdisplay7(font);
        inputdisplay7.setCharacterSize(49);
        inputdisplay7.setFillColor(Color(90,150,200));
        inputdisplay7.setPosition({430,615});

        //text7
        Text interests(font);
        interests.setString("Enter Interests "); 
        interests.setCharacterSize(33);
        interests.setFillColor(Color(80,60,100));
        interests.setPosition({420,480});  
        //input 1
        string input9="";
        RectangleShape inputbox9({270,50});
        inputbox9.setPosition({360,520});    
        inputbox9.setFillColor(Color::White);
        inputbox9.setOutlineThickness(2);
        inputbox9.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay9(font);
        inputdisplay9.setCharacterSize(40);
        inputdisplay9.setFillColor(Color(90,150,200));
        inputdisplay9.setPosition({360,515});    

        //text6
        Text country(font);
        country.setString("Enter Country "); 
        country.setCharacterSize(33);
        country.setFillColor(Color(80,60,100));
        country.setPosition({410,680});    
        //input 1
        string input8="";
        RectangleShape inputbox8({270,50});   
        inputbox8.setPosition({360,720});
        inputbox8.setFillColor(Color::White);
        inputbox8.setOutlineThickness(2);
        inputbox8.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplay8(font);
        inputdisplay8.setCharacterSize(49);
        inputdisplay8.setFillColor(Color(90,150,200));
        inputdisplay8.setPosition({440,715});
        
        Text submit2txt(font);
        submit2txt.setString("SUBMIT"); 
        submit2txt.setCharacterSize(40);
        submit2txt.setFillColor(Color::White);
        submit2txt.setPosition({440,795});

        RectangleShape userback({200,60});
        userback.setFillColor(Color(90,150,200)); 
        userback.setPosition({20,30});

        Text userbacktxt(font);
        userbacktxt.setString("BACK"); 
        userbacktxt.setCharacterSize(40);
        userbacktxt.setFillColor(Color::White);
        userbacktxt.setPosition({80,35});
     
        //for show network

       View networkView(
        FloatRect(
            Vector2f(0.f,0.f),
            Vector2f(1000.f,880.f)
        )
       );
        string networkData="";
        Text networktxt(font);
        networktxt.setLineSpacing(1.3f);
        networktxt.setCharacterSize(20);
        networktxt.setFillColor(Color::Black);
        networktxt.setPosition({10,60});
        
        RectangleShape networkback({160,60});
        networkback.setFillColor(Color(90,150,200)); 
        networkback.setPosition({830,30});

        Text networkbacktxt(font);
        networkbacktxt.setString("BACK"); 
        networkbacktxt.setCharacterSize(40);
        networkbacktxt.setFillColor(Color::White);
        networkbacktxt.setPosition({880,35});

        //for recommend Friends

        //text1

        Text recommendfritxt(font);
        recommendfritxt.setString("Recommend Friends "); 
        recommendfritxt.setCharacterSize(70);
        recommendfritxt.setFillColor(Color(70,130,180));
        recommendfritxt.setPosition({285,49});

        Text userfriend(font);
        userfriend.setString("Enter User ID "); 
        userfriend.setCharacterSize(40);
        userfriend.setFillColor(Color(70,130,180));
        userfriend.setPosition({410,230});    
        //input 1
        string friendinput="";
        RectangleShape inputboxfri({270,50});   
        inputboxfri.setPosition({360,280});
        inputboxfri.setFillColor(Color::White);
        inputboxfri.setOutlineThickness(2);
        inputboxfri.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplayfri(font);
        inputdisplayfri.setCharacterSize(49);
        inputdisplayfri.setFillColor(Color(90,150,200));
        inputdisplayfri.setPosition({450,275});
        
        Text submitfritxt(font);
        submitfritxt.setString("SUBMIT"); 
        submitfritxt.setCharacterSize(40);
        submitfritxt.setFillColor(Color::White);
        submitfritxt.setPosition({450,380});

        submitfri.setPosition({360,375}); //button has been made with all other buttons
   
        //back button
        RectangleShape backfri({270,60});
        backfri.setFillColor(Color(90,150,200)); 
        backfri.setPosition({360,480});

        Text backfritxt(font);
        backfritxt.setString("BACK"); 
        backfritxt.setCharacterSize(40);
        backfritxt.setFillColor(Color::White);
        backfritxt.setPosition({460,485});
        
        //for recommendation of friends result
        Text recommendText(font);    
        recommendText.setCharacterSize(40);
        recommendText.setFillColor(Color::Black);
        recommendText.setPosition({100,60});

        //back button
        RectangleShape backfri2({270,60});
        backfri2.setFillColor(Color(90,150,200)); 
        backfri2.setPosition({360,680});

        Text backfri2txt(font);
        backfri2txt.setString("BACK"); 
        backfri2txt.setCharacterSize(40);
        backfri2txt.setFillColor(Color::White);
        backfri2txt.setPosition({460,685});

        // bfs traversal

        Text bfsmain(font);
        bfsmain.setString("BFS TRAVERSAL"); 
        bfsmain.setCharacterSize(100);
        bfsmain.setFillColor(Color(70,130,180));
        bfsmain.setPosition({280,80});

        Text bfsuser(font);
        bfsuser.setString("Enter User ID "); 
        bfsuser.setCharacterSize(40);
        bfsuser.setFillColor(Color(70,130,180));
        bfsuser.setPosition({410,230});    
        //input 1
        string bfsinput="";
        RectangleShape inputboxbfs({270,50});   
        inputboxbfs.setPosition({360,280});
        inputboxbfs.setFillColor(Color::White);
        inputboxbfs.setOutlineThickness(2);
        inputboxbfs.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplaybfs(font);
        inputdisplaybfs.setCharacterSize(49);
        inputdisplaybfs.setFillColor(Color(90,150,200));
        inputdisplaybfs.setPosition({450,275});
        
        //submit button
        RectangleShape bfssubmit({270,60});
        bfssubmit.setFillColor(Color(90,150,200)); 
        bfssubmit.setPosition({360,369});
        
        Text bfssubtxt(font);
        bfssubtxt.setString("SUBMIT"); 
        bfssubtxt.setCharacterSize(40);
        bfssubtxt.setFillColor(Color::White);
        bfssubtxt.setPosition({440,370});

        Text bfsResultText(font);
        bfsResultText.setCharacterSize(22);
        bfsResultText.setFillColor(Color::Black);
        bfsResultText.setPosition({10,60});

        //bfs back button
        RectangleShape bfssback({270,60});
        bfssback.setFillColor(Color(90,150,200)); 
        bfssback.setPosition({360,470});

        Text  bfssbacktxt(font);
        bfssbacktxt.setString("BACK"); 
        bfssbacktxt.setCharacterSize(40);
        bfssbacktxt.setFillColor(Color::White);
        bfssbacktxt.setPosition({450,475});

        //bfs second screen
        RectangleShape bfs2({160,60});
        bfs2.setFillColor(Color(90,150,200)); 
        bfs2.setPosition({830,30});

        Text bfs2txt(font);
        bfs2txt.setString("BACK"); 
        bfs2txt.setCharacterSize(40);
        bfs2txt.setFillColor(Color::White);
        bfs2txt.setPosition({880,35});

        //for graph
        //back button
        RectangleShape graph({270,60});
        graph.setFillColor(Color(90,150,200)); 
        graph.setPosition({360,460});

        Text graphtxt(font);
        graphtxt.setString("BACK"); 
        graphtxt.setCharacterSize(40);
        graphtxt.setFillColor(Color::White);
        graphtxt.setPosition({460,460});
        
        //main header
        Text GRAPH(font);
        GRAPH.setString("GRAPH"); 
        GRAPH.setCharacterSize(70);
        GRAPH.setFillColor(Color::Black);
        GRAPH.setPosition({410,40});
        
        //input txt
        Text graphuser(font);
        graphuser.setString("Enter User ID "); 
        graphuser.setCharacterSize(40);
        graphuser.setFillColor(Color::Black);
        graphuser.setPosition({400,200});
        
        string graphinput="";
        RectangleShape inputboxgraph({270,50});   
        inputboxgraph.setPosition({360,250});
        inputboxgraph.setFillColor(Color::White);
        inputboxgraph.setOutlineThickness(2);
        inputboxgraph.setOutlineColor(Color(150,150,150));
        //output 1
        Text inputdisplaygraph(font);
        inputdisplaygraph.setCharacterSize(49);
        inputdisplaygraph.setFillColor(Color(90,150,200));
        inputdisplaygraph.setPosition({460,240});

        RectangleShape seegraph({270,60});
        seegraph.setFillColor(Color(90,150,200)); 
        seegraph.setPosition({360,350});

        Text seegraphtxt(font);
        seegraphtxt.setString("SHOW GRAPH"); 
        seegraphtxt.setCharacterSize(40);
        seegraphtxt.setFillColor(Color::White);
        seegraphtxt.setPosition({400,355});
        
        //for show graph 

        RectangleShape showgraphback({230,60});
        showgraphback.setFillColor(Color(90,150,200)); 
        showgraphback.setPosition({730,780});

        Text showgraphbacktxt(font);
        showgraphbacktxt.setString("BACK"); 
        showgraphbacktxt.setCharacterSize(40);
        showgraphbacktxt.setFillColor(Color::Black);
        showgraphbacktxt.setPosition({810,780});
        showgraphbacktxt.setPosition({810,780});

        CircleShape centerNode(50);
        centerNode.setFillColor(Color(180,150,255));
        centerNode.setOrigin({50,50});

        Text centerName(font);
        centerName.setCharacterSize(20);
        centerName.setFillColor(Color::Black);

        // looping now
        while(window.isOpen()){
            while(const std ::optional event=window.pollEvent()){

                //window closes on clicking X 
                if(event->is <Event::Closed>()){
                    window.close();
                }
                
                //for scrolling in shownetwork
                if(const auto* wheelScrolled = event->getIf<Event::MouseWheelScrolled>()){
                     if(currentScreen == "shownetwork"){
                        // SCROLL DOWN
                        if(wheelScrolled->delta < 0){
                            if(networkView.getCenter().y < 40000) {
                                networkView.move({0,20});
                            }
                        }
                        // SCROLL UP
                        else if(wheelScrolled->delta > 0){
                            if(networkView.getCenter().y > 460){
                                networkView.move({0,-20});
                            }
                        }
                    }
                }

                 //for scrolling in bfs traversal
                if(const auto* wheelScrolled = event->getIf<Event::MouseWheelScrolled>()){
                     if(currentScreen == "bfsresult"){
                        // SCROLL DOWN
                        if(wheelScrolled->delta < 0){
                            if(networkView.getCenter().y < 40000) {
                                networkView.move({0,20});
                            }
                        }
                        // SCROLL UP
                        else if(wheelScrolled->delta > 0){
                            if(networkView.getCenter().y > 460){
                                networkView.move({0,-20});
                            }
                        }
                    }
                }

                //user inputs
                if(const auto* textEntered =event->getIf<Event::TextEntered>()){
                    char typedChar =static_cast<char>(textEntered->unicode);
                    // BACKSPACE
                    if(typedChar == '\b')
                    {
                       if(activeInput == "input1"){
                            if(!input1.empty())
                            {
                                input1.pop_back();
                            }
                        }else if(activeInput == "input2"){
                            if(!input2.empty())
                            {
                                input2.pop_back();
                            }
                        }else if(activeInput == "input3"){
                            if(!input3.empty())
                            {
                                input3.pop_back();
                            }
                        }else if(activeInput == "input4"){
                            if(!input4.empty())
                            {
                                input4.pop_back();
                            }
                        }else if(activeInput == "input5"){
                            if(!input5.empty())
                            {
                                input5.pop_back();
                            }
                        }else if(activeInput == "input6"){
                            if(!input6.empty())
                            {
                                input6.pop_back();
                            }
                        }else if(activeInput == "input7"){
                            if(!input7.empty())
                            {
                                input7.pop_back();
                            }
                        }else if(activeInput == "input8"){
                            if(!input8.empty())
                            {
                                input8.pop_back();
                            }
                        }else if(activeInput == "input9"){
                            if(!input9.empty())
                            {
                                input9.pop_back();
                            }
                        }else if(activeInput == "friendinput"){
                            if(!friendinput.empty())
                            {
                                friendinput.pop_back();
                            }
                        }else if(activeInput == "bfsinput"){
                            if(!bfsinput.empty())
                            {
                                bfsinput.pop_back();
                            }
                        }else if(activeInput == "graphinput"){
                            if(!graphinput.empty())
                            {
                                graphinput.pop_back();
                            }
                        }

                    }
                    // NORMAL CHARACTERS
                    else if(typedChar >= 32 && typedChar <= 126){
                       if(activeInput == "input1"){
                            input1 += typedChar;
                        } else if(activeInput == "input2"){
                            input2 += typedChar;
                        } else if(activeInput == "input3"){
                            input3 += typedChar;
                        }else if(activeInput == "input4"){
                            input4 += typedChar;
                        }else if(activeInput == "input5"){
                            input5 += typedChar;
                        }else if(activeInput == "input6"){
                            input6 += typedChar;
                        }else if(activeInput == "input7"){
                            input7 += typedChar;
                        }else if(activeInput == "input8"){
                            input8 += typedChar;
                        }else if(activeInput == "input9"){
                            input9 += typedChar;
                        }else if(activeInput == "friendinput"){
                            friendinput += typedChar;
                        }else if(activeInput == "bfsinput"){
                            bfsinput += typedChar;
                        }else if(activeInput == "graphinput"){
                            graphinput += typedChar;
                        }
                    }
                    inputdisplay1.setString(input1);
                    inputdisplay2.setString(input2);
                    inputdisplay3.setString(input3);
                    inputdisplay4.setString(input4);
                    inputdisplay5.setString(input5);
                    inputdisplay6.setString(input6);
                    inputdisplay7.setString(input7);
                    inputdisplay8.setString(input8);
                    inputdisplay9.setString(input9);
                    inputdisplayfri.setString(friendinput);
                    inputdisplaybfs.setString(bfsinput);
                    inputdisplaygraph.setString(graphinput);

                }


                //button click events
                if(const auto* mousePressed =event->getIf<Event::MouseButtonPressed>()){
                    if(mousePressed->button ==Mouse::Button::Left){
                        Vector2f mousePos(
                         mousePressed->position
                        );
                        
                        //if screen is main
                        if(currentScreen=="main"){
                            if(AddUser.getGlobalBounds().contains(mousePos)){
                                currentScreen = "adduser";
                        }

                            if(AddFriendship.getGlobalBounds().contains(mousePos)){
                                currentScreen = "addFriendship";
                        }
                            if(ShowNetwork.getGlobalBounds().contains(mousePos)){
                                networkView.setCenter({500,440});
                                networkData =g.displayGraph();
                                currentScreen="shownetwork";
                            }
                            if(RecommendFriends.getGlobalBounds().contains(mousePos)){
                                currentScreen="recommendfriends";
                            }
                            if(BFStraversal.getGlobalBounds().contains(mousePos)){
                                currentScreen="bfs";
                            }
                            if(Exit.getGlobalBounds().contains(mousePos)){
                                currentScreen="Graph";
                            }
                            if(userback.getGlobalBounds().contains(mousePos)){
                                window.close();
                            }
                        } 
                        //if screen is show network
                        else if(currentScreen=="shownetwork"){
                            if(networkback.getGlobalBounds().contains(mousePos)){
                                currentScreen="main";
                            }

                        }
                        //if screen is add user
                        else if(currentScreen=="adduser"){
                            if(inputbox3.getGlobalBounds().contains(mousePos)){
                                activeInput = "input3";
                            }if(inputbox4.getGlobalBounds().contains(mousePos)){
                                activeInput = "input4";
                            }if(inputbox5.getGlobalBounds().contains(mousePos)){
                                activeInput = "input5";
                            }if(inputbox6.getGlobalBounds().contains(mousePos)){
                                activeInput = "input6";
                            }if(inputbox7.getGlobalBounds().contains(mousePos)){
                                activeInput = "input7";
                            }if(inputbox8.getGlobalBounds().contains(mousePos)){
                                activeInput = "input8";
                            }if(inputbox9.getGlobalBounds().contains(mousePos)){
                                activeInput = "input9";
                            }
                            if(userback.getGlobalBounds().contains(mousePos)){
                                currentScreen="main";
                            }
                            if(Submit2.getGlobalBounds().contains(mousePos)){
                                User u;
                                u.userID=stoi(input3);
                                u.name=input4;
                                u.gender=input5;
                                u.dob=input6;
                                u.interests=input9;
                                u.city=input7;
                                u.country=input8;


                                statusMessage =g.addUser(u);
                                fh.saveNetwork(g, "users.csv");

                                input3 = "";
                                input4 = "";
                                input5 = "";
                                input6 = "";
                                input7 = "";
                                input8 = "";
                                input9 = "";

                                inputdisplay3.setString("");
                                inputdisplay4.setString("");
                                inputdisplay5.setString("");
                                inputdisplay6.setString("");
                                inputdisplay7.setString("");
                                inputdisplay8.setString("");
                                inputdisplay9.setString("");
                            }

                        }
                        //if screen is add friendship
                        else if(currentScreen=="addFriendship"){
                            if(inputbox1.getGlobalBounds().contains(mousePos)){
                                activeInput = "input1";
                            }
                            if(inputbox2.getGlobalBounds().contains(mousePos)){
                                activeInput = "input2";
                            }
                            if(Back.getGlobalBounds().contains(mousePos)){
                                currentScreen="main";
                                input1 = "";
                                input2 = "";
                                inputdisplay1.setString("");
                                inputdisplay2.setString("");
                                statusMessage="";
                            }
                            if(Submit.getGlobalBounds().contains(mousePos)){
                                int id1 = stoi(input1);
                                int id2 = stoi(input2);
                                statusMessage = g.addFriend(id1,id2);
                                input1 = "";
                                input2 = "";
                                inputdisplay1.setString("");
                                inputdisplay2.setString("");
                            }

                        }
                        //if screen is recommend friends
                        else if(currentScreen=="recommendfriends") {
                            if(inputboxfri.getGlobalBounds().contains(mousePos)){
                                activeInput = "friendinput";
                            }
                            if(backfri.getGlobalBounds().contains(mousePos)){
                                currentScreen="main";
                            }
                            if(submitfri.getGlobalBounds().contains(mousePos)){
                                int uid =stoi(friendinput);
                                recommendationData=algo.recommendFriends(g,uid);
                                currentScreen="recommendresult";
                            }
                        }
                        //if screen is recommendresult
                        else if(currentScreen=="recommendresult"){
                            if(backfri2.getGlobalBounds().contains(mousePos)){
                                currentScreen="recommendfriends";
                            }

                        }
                        //if screen is bfs traversal
                        else if(currentScreen=="bfs"){
                            if(inputboxbfs.getGlobalBounds().contains(mousePos)){
                                activeInput="bfsinput";
                            }
                            if(bfssubmit.getGlobalBounds().contains(mousePos)){
                                int uid = stoi(bfsinput);
                                bfsData =algo.BFSTraversal(g, uid);
                                currentScreen="bfsresult";
                                bfsinput="";
                                inputdisplaybfs.setString("");
                            }
                            if(bfssback.getGlobalBounds().contains(mousePos)){
                                currentScreen="main";
                                bfsinput="";
                                inputdisplaybfs.setString("");
                            }

                        }
                        else if(currentScreen=="bfsresult"){
                            if(bfs2.getGlobalBounds().contains(mousePos)){
                                currentScreen="bfs";
                        }
                    }
                        //if screen is Graph
                        else if(currentScreen=="Graph"){
                            if(graph.getGlobalBounds().contains(mousePos)){
                                currentScreen="main";
                                graphinput="";
                                inputdisplaygraph.setString("");
                            }
                            if(inputboxgraph.getGlobalBounds().contains(mousePos)){
                                activeInput="graphinput";
                            }
                            if(seegraph.getGlobalBounds().contains(mousePos)){
                                selectedGraphUser = stoi(graphinput);
                                currentScreen="showgraph";
                                graphinput="";
                                inputdisplaygraph.setString("");
                            }
                        }

                        //if screen is show graph
                        else if(currentScreen=="showgraph"){
                            if(showgraphback.getGlobalBounds().contains(mousePos)){
                                currentScreen="Graph";
                            }
                            
                        }
                    
                }
            }

            Vector2i mousePos =
            Mouse::getPosition(window);

            //hover over buttons
            if(AddUser.getGlobalBounds().contains(Vector2f(mousePos))){
                    AddUser.setFillColor(Color(230, 140, 160));
                }else{
                    AddUser.setFillColor(Color(255, 182, 193));
                }
                if(userback.getGlobalBounds().contains(Vector2f(mousePos))){
                    userback.setFillColor(Color(230, 140, 160));
                }else{
                    userback.setFillColor(Color(255, 182, 193));
                }

                if(AddFriendship.getGlobalBounds().contains(Vector2f(mousePos))){
                    AddFriendship.setFillColor(Color(230, 140, 160));
                }else{
                    AddFriendship.setFillColor(Color(255, 182, 193));
                }

                if(ShowNetwork.getGlobalBounds().contains(Vector2f(mousePos))){
                ShowNetwork.setFillColor(Color(230, 140, 160));
                }else{
                ShowNetwork.setFillColor(Color(255, 182, 193));
                }

                if(RecommendFriends.getGlobalBounds().contains(Vector2f(mousePos))){
                RecommendFriends.setFillColor(Color(230, 140, 160));
                }else{
                RecommendFriends.setFillColor(Color(255, 182, 193));
                }

                if(BFStraversal.getGlobalBounds().contains(Vector2f(mousePos))){
                BFStraversal.setFillColor(Color(230, 140, 160));
                }else{
                BFStraversal.setFillColor(Color(255, 182, 193));
                }

                if(Exit.getGlobalBounds().contains(Vector2f(mousePos))){
                Exit.setFillColor(Color(230, 140, 160));
                }else{
                Exit.setFillColor(Color(255, 182, 193));
                }

                if(Submit.getGlobalBounds().contains(Vector2f(mousePos))){
                    Submit.setFillColor(Color(230, 140, 160));
                }else{
                    Submit.setFillColor(Color(255, 182, 193));
                }

                if(Back.getGlobalBounds().contains(Vector2f(mousePos))){
                    Back.setFillColor(Color(230, 140, 160));
                }else{
                    Back.setFillColor(Color(255, 182, 193));
                }
                if(Submit2.getGlobalBounds().contains(Vector2f(mousePos))){
                    Submit2.setFillColor(Color(230, 140, 160));
                }else{
                    Submit2.setFillColor(Color(255, 182, 193));
                }
                if(submitfri.getGlobalBounds().contains(Vector2f(mousePos))){
                    submitfri.setFillColor(Color(230, 140, 160));
                }else{
                    submitfri.setFillColor(Color(255, 182, 193));
                }
                if(backfri.getGlobalBounds().contains(Vector2f(mousePos))){
                    backfri.setFillColor(Color(230, 140, 160));
                }else{
                    backfri.setFillColor(Color(255, 182, 193));
                }
                if(backfri2.getGlobalBounds().contains(Vector2f(mousePos))){
                    backfri2.setFillColor(Color(230, 140, 160));
                }else{
                    backfri2.setFillColor(Color(255, 182, 193));
                }
                if(bfssubmit.getGlobalBounds().contains(Vector2f(mousePos))){
                    bfssubmit.setFillColor(Color(230, 140, 160));
                }else{
                    bfssubmit.setFillColor(Color(255, 182, 193));
                }
                if(graph.getGlobalBounds().contains(Vector2f(mousePos))){
                    graph.setFillColor(Color(230, 140, 160));
                }else{
                    graph.setFillColor(Color(255, 182, 193));
                }
                if(networkback.getGlobalBounds().contains(Vector2f(mousePos))){
                    networkback.setFillColor(Color(230, 140, 160));
                }else{
                    networkback.setFillColor(Color(255, 182, 193));
                }
                if(bfssback.getGlobalBounds().contains(Vector2f(mousePos))){
                    bfssback.setFillColor(Color(230, 140, 160));
                }else{
                    bfssback.setFillColor(Color(255, 182, 193));
                }
                if(bfs2.getGlobalBounds().contains(Vector2f(mousePos))){
                    bfs2.setFillColor(Color(230, 140, 160));
                }else{
                    bfs2.setFillColor(Color(255, 182, 193));
                }
                if(seegraph.getGlobalBounds().contains(Vector2f(mousePos))){
                    seegraph.setFillColor(Color(230, 140, 160));
                }else{
                    seegraph.setFillColor(Color(255, 182, 193));
                }
                if(showgraphback.getGlobalBounds().contains(Vector2f(mousePos))){
                   showgraphback.setFillColor(Color(230, 140, 160));
                }else{
                    showgraphback.setFillColor(Color(255, 182, 193));
                }

            
               
            //drawing everything now on screen
            
            if(currentScreen=="main"){

                window.clear( Color(245, 240, 255));

                window.draw(text1);
                window.draw(text2);

                window.draw(AddUser);
                window.draw(addUsertxt);

                window.draw(AddFriendship);
                window.draw(friendtxt);

                window.draw(ShowNetwork);
                window.draw(showtxt);

                window.draw(RecommendFriends);
                window.draw(recommendtxt);

                window.draw(BFStraversal);
                window.draw(bfstxt);

                window.draw(userback);
                window.draw(userbacktxt);

                window.draw(Exit);
                window.draw(exittxt);

            }

            //screen is adduser 
            else if(currentScreen=="adduser"){
                window.clear(Color(245, 240, 255));
                window.draw(usertxt);

                window.draw(userid);
                window.draw(inputbox3);
                window.draw(inputdisplay3);
                
                window.draw(username);
                window.draw(inputbox4);
                window.draw(inputdisplay4);

                window.draw(gender);
                window.draw(inputbox5);
                window.draw(inputdisplay5);

                window.draw(DOB);
                window.draw(inputbox6);
                window.draw(inputdisplay6);

                window.draw(interests);
                window.draw(inputbox9);
                window.draw(inputdisplay9);

                window.draw(city);
                window.draw(inputbox7);
                window.draw(inputdisplay7);

                window.draw(country);
                window.draw(inputbox8);
                window.draw(inputdisplay8);

                window.draw(Submit2);
                window.draw(submit2txt);

                window.draw(userback);
                window.draw(userbacktxt);

                statustext2.setString(statusMessage);
                window.draw(statustext2);
                
            }

            //screen changed to add friendhsip 
            else if(currentScreen =="addFriendship"){
                window.clear(Color(245, 240, 255));
                window.draw(friendtitle);

                window.draw(user1);
                window.draw(user2);

                window.draw(inputbox1);
                window.draw(inputdisplay1);

                window.draw(inputbox2);
                window.draw(inputdisplay2);

                window.draw(Submit);
                window.draw(submittxt);

                window.draw(Back);
                window.draw(backtxt);

                statusText.setString(statusMessage);
                window.draw(statusText);
            }

            else if(currentScreen=="shownetwork"){
                window.clear(Color(245, 240, 255));
                window.setView(networkView);
                networktxt.setString(networkData);
                window.draw(networktxt); 
                window.draw(networkback);
                window.draw(networkbacktxt);
                window.setView(window.getDefaultView());
            }

            else if(currentScreen=="recommendfriends"){
                window.clear(Color(245, 240, 255));
                window.draw(recommendfritxt);
                window.draw(inputboxfri);
                window.draw(inputdisplayfri);
                window.draw(userfriend);
                window.draw(submitfri);
                window.draw(submitfritxt);
                window.draw(backfri);
                window.draw(backfritxt);

            }

            else if(currentScreen=="recommendresult"){
                window.clear(Color(245, 240, 255));
                recommendText.setString(recommendationData);
                window.draw(recommendText);

                window.draw(backfri2);
                window.draw(backfri2txt);
            }

            else if(currentScreen=="bfs"){
                window.clear(Color(245, 240, 255));
                window.draw(bfsmain);
                window.draw(bfsuser);
                window.draw(inputboxbfs);
                window.draw(inputdisplaybfs);
                window.draw(bfssubmit);
                window.draw(bfssubtxt);
                window.draw(bfssback);
                window.draw(bfssbacktxt);
            }

            else if(currentScreen=="bfsresult"){
                window.clear(Color(245, 240, 255));
                window.setView(networkView);
                bfsResultText.setString(bfsData);
                window.draw(bfsResultText);
                window.setView(window.getDefaultView());
                window.draw(bfs2);
                window.draw(bfs2txt);
            }

            else if(currentScreen=="Graph"){
                window.clear(Color(245, 240, 255));
                window.draw(GRAPH);
                window.draw(graph);
                window.draw(graphtxt);
                window.draw(graphuser);
                window.draw(inputboxgraph);
                window.draw(inputdisplaygraph);
                window.draw(seegraph);
                window.draw(seegraphtxt);
            }

            else if(currentScreen=="showgraph"){
                window.clear(Color(245, 240, 255));
                window.draw(showgraphback);
                window.draw(showgraphbacktxt);

                int uid = selectedGraphUser;
                User& centerUser = g.users[uid];
                map<int, Vector2f> friendPos;
                vector<int> friends = g.getFriends(uid);

                set<int> fof;

                for(int f : friends){
                    vector<int> temp = g.getFriends(f);
                    for(int x : temp){
                        if(x != uid){
                            fof.insert(x);
                        }
                    }
                }
                for(int f : friends){
                    fof.erase(f);
                }             
                //direct friends
                float radius = 200;
                int n = friends.size();
                //direct friend loop
                for(int i=0; i<n; i++){
                    float angle =(2 * 3.14159f * i) / n;
                    float x =500 + radius * cos(angle);
                    float y =400 + radius * sin(angle);
                    friendPos[friends[i]] = {x,y};
                    Vertex line[2];
                    line[0].position = {500.f,400.f};
                    line[1].position = {x,y};
                    line[0].color = Color(80,60,100);
                    line[1].color = Color(80,60,100);
                    window.draw(line, 2, PrimitiveType::Lines);
                    CircleShape friendNode(35);
                    friendNode.setFillColor(Color(255,180,200));
                    friendNode.setOrigin({35,35});
                    friendNode.setPosition({x,y});
                    window.draw(friendNode);

                    Text friendName(font);

                    friendName.setCharacterSize(16);
                    friendName.setFillColor(Color::Black);
                    friendName.setString( g.users[friends[i]].name );
                    friendName.setPosition({x - 35, y + 45} );
                    window.draw(friendName);
                }

                //friends of friends
                float outerRadius = 380;
                int m = fof.size();
                int index = 0;

                for(int id : fof){
                    float angle =(2 * 3.14159f * index) / m;
                    float x =500 + outerRadius * cos(angle);
                    float y =400 + outerRadius * sin(angle);
                    CircleShape fofNode(25);
                    fofNode.setFillColor( Color(170,255,190));
                    fofNode.setOrigin({25,25});
                    fofNode.setPosition({x,y});
                    window.draw(fofNode);
                    Text fofName(font);
                    fofName.setCharacterSize(14);
                    fofName.setFillColor(Color::Black);
                    fofName.setString(g.users[id].name);
                    fofName.setPosition({x - 35, y + 35});

                    for(int f : friends){
                        vector<int> temp = g.getFriends(f);
                        for(int x2 : temp){
                            if(x2 == id){
                                Vertex line[2];
                                line[0].position = friendPos[f];
                                line[1].position = {x,y};
                                line[0].color = Color::White;
                                line[1].color = Color::White;
                                window.draw(line,2,PrimitiveType::Lines);
                                break;
                            }
                        }
                    }
                    window.draw(fofName);
                    index++;
                }
                centerNode.setPosition({500,400});
                window.draw(centerNode);      
                centerName.setString(centerUser.name);
                centerName.setPosition({470,470});
                window.draw(centerName);
            }
            window.display();
        }   
}
}