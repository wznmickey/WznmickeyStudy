function ex2()
    print_house();
    print_car();
end
function print_house()
    print_building();
    print_roof();
    print_window();
    print_door();
end
function print_building()
    x1=linspace(0,60,100);
    y1=x1*0;
    y2=x1*0+40;
    plot(x1,y1,'k',x1,y2,'k');
    axis equal;
    hold on;
    y1=linspace(0,40,100);
    x1=y1*0;
    x2=y1*0+60;
    plot(x1,y1,'k',x2,y1,'k');
    xlim([-20,150]);
    ylim([0,60]);
end
function print_roof()
    x1=linspace(0,30,50);
    y1=x1/2+40;
    x2=linspace(30,60,50);
    y2=-x2/2+70;
    plot(x1,y1,'k',x2,y2,'k');
end
function print_window()
    x1=linspace(15,30,100);
    y1=x1*0+10;
    y2=x1*0+25;
    plot(x1,y1,'k',x1,y2,'k');
    y1=linspace(10,25,100);
    x1=y1*0+15;
    x2=y1*0+30;
    plot(x1,y1,'k',x2,y1,'k');
end
function print_door()
    x1=linspace(45,55,100);
    y1=x1*0;
    y2=x1*0+30;
    plot(x1,y1,'k',x1,y2,'k');
    y1=linspace(0,30,100);
    x1=y1*0+45;
    x2=y1*0+55;
    plot(x1,y1,'k',x2,y1,'k');
end
function print_car()
    print_wheel(80);
    print_wheel(120);
    print_maincar();
end
function print_wheel(x)
    alpha=linspace(0,2*pi);
    x=5*cos(alpha)+x;
    y=5*sin(alpha)+5;
    plot(x,y,'k');
end
function print_maincar()
    x1=linspace(70,75);
    x2=linspace(85,115);
    x3=linspace(125,130);
    y1=x1*0+5;
    y2=x2*0+5;
    y3=x3*0+5;
    plot(x1,y1,'k',x2,y2,'k',x3,y3,'k');
    x1=linspace(70,80);
    x2=linspace(80,120);
    x3=linspace(120,130);
    y1=x1*1.5-100;
    y2=x2*0+20;
    y3=x3*(-1.5)+200;
    plot(x1,y1,'k',x2,y2,'k',x3,y3,'k');
    hold off;
end