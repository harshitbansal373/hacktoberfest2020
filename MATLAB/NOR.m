function output = nor(A,B)
n=length(A);
output=zeros(1,n);
for j=1:n
    if(A(j)==1 || B(j)==1)
        output(j)=0;
    elseif(A(j)==0 && B(j)==0)
        output(j)=1;
    end
end