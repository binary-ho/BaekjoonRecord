# [Gold V] 동전 2 - 2294 

[문제 링크](https://www.acmicpc.net/problem/2294) 


배낭문제와 유사한 DP. 총 가격을 dp값으로 삼아 1원 부터 K원까지 전부 돌아가면서 표현 가능한 최소 코인 갯수를 갱신해 나간다.
```cpp
  std::sort(coinVector.begin(), coinVector.end(), less<>());
  coinVector.erase(unique(coinVector.begin(), coinVector.end()), coinVector.end());

  for (int price = 1; price <= K; price++) {
      for (int coin : coinVector) {
          if (price - coin <= 0) continue;
          dp[price] = min(dp[price], dp[price - coin] + 1);
      }
  }
```
유니크 제거를 매번 검색하는데, 이번엔 좀 외우자. <br>
정렬 -> erase(유니크)이다. <br>
중복 입력이 있을 수 있는데, 갯수를 셀 때 방해되므로 전부 지워 주었고, 내림차순 정렬은 최소 동전 갯수로 가격을 표현하기 위해 도입했으나 사실 필요 없어 보인다.

### 성능 요약

메모리: 2064 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.</p>

<p>사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.</p>

### 입력 

 <p>첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.</p>

### 출력 

 <p>첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.</p>

