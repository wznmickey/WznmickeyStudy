function [B]=generate_permutations_adjusted(A,l,num)%A is the set and l is the length
    persistent temp_l;
    temp_l=numel(A);
    if l==1
        % reference: The Art of Computer Programming Vol 2: Seminumercial
        % Algorithms
        for i=temp_l:-1:2
            j=randi(i);
            [A(i),A(j)]=swap(A(i),A(j));
        end
        for i=1:num
            B(i,:)=[A(i)];
        end
    else
        %get num random number
        % reference: The Art of Computer Programming Vol 2: Seminumercial
        % Algorithms
        temp_A=1:power(temp_l,l);
        for j=1:power(temp_l,l)
            k=floor(j*rand)+1;
            temp_A(j)=temp_A(k);
            temp_A(k)=j;
        end
        temp_A([num+1:power(temp_l,l)])=[];
        temp_A=floor((temp_A-1)./power(temp_l,l-1))+1;
        temp_B=zeros(temp_l,1);
        for i=1:num
            temp_B(temp_A(i))=temp_B(temp_A(i))+1;
        end
        temp_i=0;
        for i=1:temp_l
            if (temp_B(i)>0)
                temp_set=generate_permutations_adjusted(A,l-1,temp_B(i));
                for j=1:temp_B(i)
                    temp_i=temp_i+1;
                    B(temp_i,:)=[temp_set(j,:),A(i)];
                end
            end
        end
    end
end