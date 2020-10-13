function ex1()
    n=uint64(63);
    final_ans=((power(2,n)-1)*2+1);
    % directly use power(2,64)-1 will make the ans wrong since the maximum
    % of uint64 is 2^64-1,so the power(2,64) can not have correct ans.
    disp(final_ans);
end