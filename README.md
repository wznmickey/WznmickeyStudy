# Project 1

### How to use

**RUN main.m**

You will be asked to input several numbers,after that one crossroad will appear with lights.
Several cars will appear based on your input.
If cars cross the road successfully, you will win, or you will lose.

### Features
 - check whether inputs of light time may lead to accidents (partly)
 - change the color based on the iuput
 - assign cars into 4 lines
 - print the crossroad
 - draw cars
 - check whether there is an accident
### Bugs
 - the figure sometimes will reopen if the user close it before the end of the animation

### Algorithm

#### the motion of the cars
- input: x,y,w,runtime,p,n,car,car_list,o
- output: animation

|name|meaning|
|---|---|
|x|info in x axis|
|y|info in y axis|
|w|width of road|
|n|num of cars|
|car_list| info of car|
|o|time of orange light|

1. run_flag←true;
2. draw_flag←false;
3. if there is need to check whether cars' status should change
   1. for i = 1 to car(1).num+car(2).num
      1. if (car_list(i).ignore==true && car_list(i).first==true)
      2. car_list(i).run←car_list(i).really_ignore←true;
      3. if i^th car and (i+1)^th car have same direction (if there is (i+1)^th car) then
         1. car_list(i+1).first←true;
         2. car_list(i).first←false;
      4. else car_list(i).run←false;
   2. end
4. if (x.light.status==3 && x.light.change==true)
   1. for i = 1 to car(1).num+car(2).num
   2. car_list(i).run←true;
   3. i←i+1
   4. if (i<=car(1).num+car(2).num-1) goto `4.2`
5. if (((o==0||runtime.before==0) && y.light.status==1 && y.light.change==true) || (y.light.status==2 && y.light.change==true))
   1. i←car(1).num+car(2).num+1;
   2. if (car_list(i).ignore==true && car_list(i).first==true)
      1. car_list(i).run←true;
      2. car_list(i).really_ignore←true;
      3. if (i+1<=n && car_list(i+1).line==car_list(i).line)
         1. car_list(i+1).first←true;
         2. car_list(i).first←false;
      4. else car_list(i).run←false;
   3. i←i+1;
   4. if (i<=n-1) goto `5.2`
6. if (y.light.status==3 && y.light.change==true)
   1. i←car(1).num+car(2).num+1
   2. car_list(i).run←true;
   3. i←i+1;
   4. if (i<=n-1) goto `6.2`
7.         end
8.     end
9.     for i←1:n
10.        if (car_list(i).line==1 && car_list(i).x>-w/2-3)
11.            car_list(i).run←true;
12.            if (i+1<=n && car_list(i+1).line==car_list(i).line)
13.                car_list(i+1).first←true;
14.                car_list(i).first←false;
15.            end
16.        end
17.        if (car_list(i).line==2 && car_list(i).x<w/2+3)
18.            car_list(i).run←true;
19.            if (i+1<=n && car_list(i+1).line==car_list(i).line)
20.                car_list(i+1).first←true;
21.                car_list(i).first←false;
22.            end
23.        end
24.        if (car_list(i).line==3 && car_list(i).y<w/2+3)
25.            car_list(i).run←true;
26.            if (i+1<=n && car_list(i+1).line==car_list(i).line)
27.                car_list(i+1).first←true;
28.                car_list(i).first←false;
29.            end
30.        end
31.        if (car_list(i).line==4 && car_list(i).y>-w/2-3)
32.            car_list(i).run←true;
33.            if (i+1<=n && car_list(i+1).line==car_list(i).line)
34.                car_list(i+1).first←true;
35.                car_list(i).first←false;
36.            end
37.        end
38.    end
39.    for i←1:n
40.        if (car_list(i).run==true)
41.            if (car_list(i).line==1)
42.                car_list(i).x←car_list(i).x+runtime.last*10;
43.            end
44.            if (car_list(i).line==2)
45.                car_list(i).x←car_list(i).x-runtime.last*10;
            end
            if (car_list(i).line==3)
                car_list(i).y←car_list(i).y-runtime.last*10;
            end
            if (car_list(i).line==4)
                car_list(i).y←car_list(i).y+runtime.last*10;
            end
        end
        if (abs(car_list(i).x)<=50 && abs(car_list(i).y)<=50 && car_list(i).isdraw==false)
            hold on;
            if (car_list(i).line<=2)
                car_list(i).draw=rectangle('Position',[car_list(i).x-3 car_list(i).y-2 6 4],'FaceColor','r');
            end
            if (car_list(i).line>=3)
                car_list(i).draw=rectangle('Position',[car_list(i).x-2 car_list(i).y-3 4 6],'FaceColor','r');
            end
            car_list(i).isdraw←true;
            hold off;
            draw_flag←true;
        else
            if (car_list(i).line<=2 && abs(car_list(i).x)<=50)
                car_list(i).draw.Position←[car_list(i).x-3 car_list(i).y-2 6 4];
                draw_flag←true;
            end
            if (car_list(i).line>=3 && abs(car_list(i).y)<=50)
                car_list(i).draw.Position←[car_list(i).x-2 car_list(i).y-3 4 6];
                draw_flag←true;
            end
        end
        drawnow;
    end
    [run_flag]←checkcrash(car_list,n,w);
end
```


function [g,o,r]←init_light()
    color←["green","orange","red"];
    temp_st1←"The time for ";
    temp_st2←" light is:";
    g←input(temp_st1+color(1)+temp_st2);
    o←input(temp_st1+color(2)+temp_st2);
    r←input(temp_st1+color(3)+temp_st2);
    if (g+o~=r) 
        disp("ERROR!");
        disp("The time for green plus the time for orange does not equal to the time for red.It will lead to traffic accidents.Please input again.");
        [g,o,r]←init_light();
   end
end

function [time,x,y]←start()
    time←0;
    x.light.status←3;% 1-r,2-o,3-g
    x.light.time←0;
    y.light.status←1;
    y.light.time←0;
    x.light.change←true;
    y.light.change←true;
end

function [x]←checklight(time,x,r,o,g)
    x.light.time←x.light.time+time;
    if (x.light.status==2 && x.light.time>=o)
        x.light.status←1;
        x.light.time←x.light.time-o;
        x.light.change←true;
    end
    if (x.light.status==1 && x.light.time>=r)
        x.light.status←3;
        x.light.time←x.light.time-r;
        x.light.change←true;
    end
    if (x.light.status==3 && x.light.time>=g)
        x.light.status←2;
        x.light.time←x.light.time-g;
        x.light.change←true;
        if (o==0)
            x.light.status←1;
        end
    end
end

function draw_crossroad(w)
    figure;
    w←w/2;
    xn←linspace(-35,-w,35);
    yn←linspace(-35,-w,35);
    xp←linspace(w,35,35);
    yp←linspace(w,35,35); 
    x1←xn*0-w;
    x2←-x1;
    x3←xn*0;
    y1←yn*0+w;
    y2←-y1;
    y3←yn*0;
    hold on; 
    plot(xn,y1,'black');
    plot(xn,y2,'black');
    plot(xp,y1,'black');
    plot(xp,y2,'black');
    plot(x1,yn,'black');
    plot(x2,yn,'black');
    plot(x1,yp,'black');
    plot(x2,yp,'black');
    plot(xn,y3,'--black');
    plot(xp,y3,'--black');
    plot(x3,yn,'--black');
    plot(x3,yp,'--black');
    hold off;
    xlim([-30 30]);
    ylim([-30 30]);
    pbaspect([1 1 1]);
end

function draw_light(x,y,w,an1,an2,time)
    w←w/2;
    color←["r","#ffa500","g"];
    hold on;
    if x.light.change==true
        clearpoints(an1);
        an1 ← animatedline('Color',color(x.light.status),'LineStyle','none','Marker','o','MarkerSize',15,'MarkerFaceColor',color(x.light.status));
        addpoints(an1,w,w);
        addpoints(an1,-w,-w);
    end
    if y.light.change==true
        clearpoints(an2);
        an2 ← animatedline('Color',color(y.light.status),'LineStyle','none','Marker','o','MarkerSize',15,'MarkerFaceColor',color(y.light.status));
        addpoints(an2,-w,w);
        addpoints(an2,w,-w);
    end
        if (1/time.last>250) title("FPS>250");
        else title("FPS:"+num2str(floor(1/time.last),'%05.3d'));
        end
    hold off;
end



function[run_flag]←checkcrash(car_list,n,w)
    run_flag←true;
    risk_car1←[car_list(1)];
    l_risk_car1←0;
    risk_car2←[car_list(1)];
    l_risk_car2←0;
    for i←1:n
        if ((abs(car_list(i).x)<=w) && (abs(car_list(i).y)<=w))
            if car_list(i).line<=2
                risk_car1(1,l_risk_car1+1)←car_list(i);
                l_risk_car1←l_risk_car1+1;
            end
            if car_list(i).line>=3
                risk_car2(1,l_risk_car2+1)←car_list(i);
                l_risk_car2←l_risk_car2+1;
            end
        end
    end
    for i←1:l_risk_car1
        for j←1:l_risk_car2
            if (abs(risk_car1(1,i).x-risk_car2(1,j).x)<=5 && abs(risk_car1(1,i).y-risk_car2(1,j).y)<=5)
                run_flag←false;
                return;
            end
        end
    end
end

function go(r,o,g,w,p,n,car,car_list)
    [time,x,y]←start();
    draw_crossroad(w);
    an1 ← animatedline;
    an2 ← animatedline;
    runtime.before←0;
    runtime.now←0;
    tic;
    run_flag←true;
    draw_flag←true;
    while (run_flag && draw_flag)
        runtime.before←runtime.now;
        runtime.now←toc;
        runtime.last←runtime.now-runtime.before;
        [x]←checklight(runtime.last,x,r,o,g);
        [y]←checklight(runtime.last,y,r,o,g);
        draw_light(x,y,w,an1,an2,runtime);
        [car_list,run_flag,draw_flag]←draw_car(x,y,w,an1,an2,runtime,p,n,car,car_list,o);
        x.light.change←false;
        y.light.change←false;
        drawnow;
    end
    if run_flag==false
        text(-30,0,"WRONG!!!CRASHED!!!YOU LOSE.",'Color','red','FontSize',14)
        disp("WRONG!!!CRASHED!!!YOU LOSE.");
    else
        text(-30,0,"SUCCESS!!!YOU WIN.",'Color','red','FontSize',14)
        disp("SUCCESS!!!YOU WIN.");
    end
end

function [a,b]←swap(a,b)
    temp←a;
    a←b;
    b←temp;
end

function [B]←generate_permutations(A,l) %A is the set and l is the length
    temp_l←numel(A);
    if l==1
        for i←1:temp_l
            B(i,:)←[A(i)];
        end
    else
        temp_set←generate_permutations(A,l-1);
        temp_size←size(temp_set,1);
        temp_i←0;
        for i←1:temp_l
            for j←1:temp_size
                temp_i←temp_i+1;
                B(temp_i,:)←[temp_set(j,:),A(i)];
            end
        end
    end
end

function [B]←generate_permutations_adjusted(A,l,num)%A is the set and l is the length
    persistent temp_l;
    temp_l←numel(A);
    if l==1
        % reference: The Art of Computer Programming Vol 2: Seminumercial
        % Algorithms
        for i←temp_l:-1:2
            j←randi(i);
            [A(i),A(j)]←swap(A(i),A(j));
        end
        for i←1:num
            B(i,:)←[A(i)];
        end
    else
        %get num random number
        % reference: The Art of Computer Programming Vol 2: Seminumercial
        % Algorithms
        temp_max←power(temp_l,l);
        temp_A←1:temp_max;
        for j←1:num
            k←randi(temp_max-j+1)+j-1;
            [temp_A(k),temp_A(j)]←swap(temp_A(k),temp_A(j));
        end
        temp_A([num+1:temp_max])←[];
        temp_A←floor((temp_A-1)./power(temp_l,l-1))+1;
        temp_B←zeros(temp_l,1);
        for i←1:num
            temp_B(temp_A(i))←temp_B(temp_A(i))+1;
        end
        temp_i←0;
        for i←1:temp_l
            if (temp_B(i)>0)
                temp_set←generate_permutations_adjusted(A,l-1,temp_B(i));
                for j←1:temp_B(i)
                    temp_i←temp_i+1;
                    B(temp_i,:)←[temp_set(j,:),A(i)];
                end
            end
        end
    end
end

### To-do list(Besides requirment)
- let 2 direction have different red-orange-green light time as long as no situation of both being green happened.
- ~~use timestamp rather than pause() to control the speed~~
- ~~show FPS in the screen~~