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
