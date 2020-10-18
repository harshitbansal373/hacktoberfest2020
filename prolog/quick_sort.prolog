Domains
    list = integer*.
Predicates
    quicksort(list,list).
    split(integer,list,list,list).
    concatenate(list,list,list).
    print(list).    
Clauses
    quicksort([],[]).
    quicksort([Head|Tail],SortedList) :-
        split(Head,Tail,SList,BList),
        quicksort(SList,SList1),
        quicksort(BList,BList1),
        concatenate(SList1,[Head|Blist1],SortedList),
        print(SortedList). 
    split(_,[],[],[]).
    split(Item,[Head1|Tail1],[Head1|SList],BList) :-
        Item > Head1 , ! ,
        split(Item,Tail1,SList,BList).
    split(Item,[Head1|Tail1],SList,[Head1|BList]) :-
        split(Item,Tail1,SList,BList).
    concatenate([],List,List).
    concatenate([Item|List1],List2,[Item|List3]) :-
        concatenate(List1,List2,List3).
    print([]) :- nl.
    print([Head|Tail]) :-
        write(Head," "),
        print(Tail).
