function [B]=generate_permutations(A,l) %A is the set and l is the length
    temp_l=numel(A);
    if l==1
        for i=1:temp_l
            B(i,:)=[A(i)];
        end
    else
        temp_set=generate_permutations(A,l-1);
        temp_size=size(temp_set,1);
        temp_i=0;
        for i=1:temp_l
            for j=1:temp_size
                temp_i=temp_i+1;
                B(temp_i,:)=[temp_set(j,:),A(i)];
            end
        end
    end
end

