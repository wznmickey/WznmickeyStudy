l=input('');
left=mod (l,400);
lap=(l-left)/400;% can also use idivide
left=400-left;
disp(lap);
disp(left);