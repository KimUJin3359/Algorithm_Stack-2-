# Stack-2-

### 계산기
- 문자열 수식 계산의 일반적 방법
  - 중위 표기법의 수식을 후위 표기법으로 변경
  - 후위 표기법의 수식을 스택으 ㄹ이용하여 계산

### 백트래킹
- 해를 찾는 도중 막히면 되돌아가서 다시 해를 찾아가는 기법
- 백트래킹 기법은 최적화 문제와 결정 문제를 해결할 수 있음
- 결정 문제
  - 문제의 조건을 만족하는 해가 존재하는지의 여부를 yes or no로 답하는 문제
  - 미로찾기, n-Queen, Map coloring, Subset sum

#### 백트래킹과 깊이우선 탐색과의 차이
- 가지치기 : 해결책으로 이어질 것 같지 않는 경로를 따라가지 않음으로써 시도의 횟수를 줄임
- 즉, 깊이우선 탐색은 모든 경로를 추적하는데 비해 백 트래킹은 불필요한 경로를 조기 차단

### Divide and Conquer
- Divide : 해결할 문제를 여러 개의 작은 부분으로 나눔
- Conquer : 작은 부분을 각각 해결
- Combine : 해결된 해답을 모음

### 정렬
- 퀵 정렬
  - 주어진 배열을 두 개로 분할하고, 각각을 정렬
  - 분할할 때 기준 아이템 중심으로 작은 것은 왼편, 큰 것은 오른편에 위치
  - 그렇기 때문에, 합병 작업이 필요하지 않음
```
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void quick_sort(int a[], int begin, int end)
{
  if (begin < end)
  {
    int p = a[(begin + end) / 2];
    int i = begin;
    int j = end;
    
    while (i <= j)
    {
      while (a[i] < p)
        i++;
      while (a[j] > p)
        j--;
      if (i <= j)
      {
        swap(data[i], data[j]);
        i++;
        j--;
      }
    }
    quick_sort(a, i, right);
    quick_sort(a, left, j);
  }
}
```

#### 관련 문제
[1.Broken Calculator](https://github.com/KimUJin3359/Stack-2-/tree/master/Broken_Calculator)
- 계산기의 버튼이 많이 고장 나서 몇 개의 숫자 버튼과 곱하기 버튼, 계산 버튼밖에 남아있지 않음
- 숫자 X를 계산하고 싶을 때, 눌러야 하는 최소 버튼의 수를 구하는 문제
- 접근 방법
  - 만들 수 있는 숫자를 판단할 수 있는 배열생성(index = 만들 수 있는 숫자, value = 만들기 위해 버튼을 눌러야 하는 횟수)
  - 백트래킹을 통해 arr을 채워넣음
    - 가지치기 조건 : 만들어진 값이 찾아야 되는 값보다 큰 경우 / 만들 값의 길이가 찾아야 되는 값의 길이보다 긴 경우)
  - 채워진 배열의 큰 수(찾아야되는 값 보다 작거나 같은)부터 1보다 클 때까지, 나누기를 하여 나머지가 0이 되는 경우 계속해서 나눠줌
  - 다 나눠진 값이 1일 경우 해당 횟수 출력, 그렇지 않은 경우 만들 수 없는 수
  
[2.Calculator](https://github.com/KimUJin3359/Stack-2-/tree/master/Calculator)
- 연산자(+, \*) 및 괄호가 존재할 때 해당 연산의 결과값을 출력하는 문제
- 접근 방법
  - 해당 문자가 숫자인 경우, 숫자가 아닌 값이 나올 때까지 축적 후 atoi하여 number stack에 push
  - ' ( '인 경우, 연산자 stack에 push
  - ' ) '인 경우, ' ( '가 나올 떄 까지 연산자 하나 pop, 숫자 두개 pop하여 계산 후 그 결과값을 number stack에 push
  - ' \* '인 경우, 연산자 stack에 push(' \* '의 우선순위가 무엇보다 높기 때문에 앞에 있는 연산을 먼저 수행할 필요가 없음)
  - ' + '인 경우, 연산자 stack에 기존에 존재하던 연산자들 전부 pop(' + '의 우선순위가 가장 낮기 때문에 앞에 있던 연산들을 모두 수행 후 ' + '연산 수행, (이 나오면 pop을 멈춤)
  - 연산자 stack의 사이즈가 0이 될 때까지 pop하며 연산을 수행
  
[3.Highshelf](https://github.com/KimUJin3359/Stack-2-/tree/master/Highshelf)
- 높이가 B인 선반이 하나 있는데, 이 서점에 있는 N명의 점원들이 선반 위에 올려놓은 물건을 사용하려 함
- 점원들이 쌓는 탑은 점원 1명 이상으로 구성, 탑의 높이는 2명 이상일 경우 탑을 만든 모든 점원의 키의 합과 같음
- 높이가 B이상인 탑 중에서 B와 가장 차이가 적은 탑을 구하는 문제
- 접근 방법
  - 부분 집합을 이용한 완전탐색

[4.Password](https://github.com/KimUJin3359/Stack-2-/tree/master/Password)
- 같은 번호가 연속된 쌍들을 소거하고 남은 번호를 비밀번호로 쓰고자 할 때, 주어진 입력값에 대한 비밀번호를 구하는 문제

[5.Sequence](https://github.com/KimUJin3359/Stack-2-/tree/master/Sequence)
- V개의 작업이 존재
- 선행 작업이 끝나야 후행 작업을 할 수 있을 때, 일을 끝내는 순서를 출력하는 문제
