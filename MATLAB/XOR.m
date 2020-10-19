function output = Xor(A,B)
n=length(A);
output=zeros(1,n);
for i=1:n
    if((A(i)==1 && B(i)==1)||(A(i)==0 && B(i)==0))
        output(i)=0;
    else
        output(i)=1;
    end
end