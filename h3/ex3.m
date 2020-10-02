function ex3()
    Type={'Jumpers';'Jumpers';'Jumpers';'Trousers';'Trousers';'Trousers';'T-shirts';'T-shirts';'T-shirts';'T-shirts';'T-shirts'};
    Color={'Blue';'Brown';'Green';'Black';'Grey';'White';'Blue';'Green';'Red';'White';'Yellow'};
    Quantity=[2;3;5;3;2;1;1;2;3;2;1];
    Bought=[datetime(2005,04,01);
        datetime(2005,02,01);
        datetime(2015,01,01);
        datetime(2012,06,01);
        datetime(2011,04,01);
        datetime(2013,12,01);
        datetime(2010,05,01);
        datetime(2014,09,01);
        datetime(2012,01,01);
        datetime(2008,03,01);
        datetime(2012,11,01)];
   Goods=table(Type,Color,Quantity,Bought);
   Goods=sortrows(Goods,3,'descend');
   ans1=char(Goods.Type(1));
   ans2=char(Goods.Color(1));
   fprintf(ans1);
   fprintf(' ');
   fprintf(ans2);
   fprintf('\n');
   Good.age=(datetime(2020,10,01)-Goods.Bought);
   ans3=fix(mean(years(Good.age)));
   disp(ans3);
end