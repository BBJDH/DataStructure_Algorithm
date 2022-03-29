/*
버블 정렬
왼쪽에서 오른쪽으로 가면서 거품으로 묶는다
오름차순(작은 수에서 큰 수로) : 묶은 두 개의 숫자를 비교해서 작은것을 왼쪽으로 보낸다
내립타순(큰 수에서 작은 수로) : 묶은 두 개의 숫자를 비교해서 큰 것을 왼쪽으로 보낸다
->오름차순의 경우
5 1 6 4 2 3 [5와 1 비교] 
1 5 6 4 2 3 [바뀐 5와 6비교]
1 5 6 4 2 3 [6과 4비교]
1 5 4 6 2 3 [6과 2비교]
1 5 4 2 3 6 [6과 3비교]
1 5 4 2 3 6 [1과 5비교]
1 5 4 2 3 6 [5과 4비교]
1 4 5 2 3 6 [5과 2비교]
1 4 2 5 3 6 [5과 2비교]
1 4 2 5 3 6 [5과 3비교]
1 4 2 3 5 6 [5과 6비교]
1 4 2 3 5 6 [1과 4비교]
1 4 2 3 5 6 [4과 2비교]
1 2 4 3 5 6 [4과 3비교]
1 2 3 4 5 6 [4과 5비교]    ==정렬 완료 되었지만 끝까지 간다 O(n^2)
							->때문에 비교할때 정렬이 종료되었는지 확인 해 줄 필요가 있다(느린정렬)
							->비교시 스왑이 일어나는 경우 count를 증가하고 count가 0이면 정렬 완료 


*/