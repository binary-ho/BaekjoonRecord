# [unrated] 미로 탈출 명령어 - 150365 

처음에 좀 복잡하게 생각했지만 dfs로 해결할 수 있었다. <br>
단, 정말 경우의 수가 많기 때문에 적절히 끊어줘야 했다. <br>
3가지 기준으로 dfs를 끊어주니 통과할 수 있었다. <br>
1. 항상 최소 루트를 유지하고, <br> 최소 루트가 아닌 루트가 만들어질 가능성이 있다면 더 탐색하지 않음
2. 더 걸을 수 있는 횟수가 정해져 있는데, <br> 현재 위치에서 목적지까지의 거리 보다 남은 걸은 횟수가 작아서 절대 도착할 수 없는 경우
3. 지금 부터 목적지까지 최단거리로 도착한다고 생각했을 때, <br> 이후에도 강제로 걸어야 하는 걸음 수가 남아 있는 경우 <br> 남은 걸음 수가 짝수여야 한다. <br> 홀수인 경우 다시 도착지점으로 돌아올 수 없기 때문!


## 1번 조건
루트를 string으로 표시한 다음 최소 루트를 찾으면 갱신한다. <br>
그리고 최소 루트 보다 큰 루트가 만들어질 가능성이 있다면 진행 중지. <br>
알파벳 순으로 d l r u 였기 때문에 이 순서로 탐색하면서 루트를 만들어 갔다. 

## 2번, 3번 조건
지도는 바둑판 형식이며, 막힌 길이 없다. <br>
때문에 좌표 차이의 절대값을 이용하면 손 쉽게 최단 경로를 통해 목적지까지 가는 거리를 구할 수 있었다. <br>
이를 이용해 더 걸을 수 있는 횟수만큼 걸었을 때 과연 도착할 수 있는지? <br>
그리고 더 걸을수 있는 횟수만큼 '강제로' 걸을 때, 목적지에서 끝낼 수 있는지를 따졌다. <br> <br>

2번 조건을 떠올리기가 많이 어려웠는데, 같은 연도에 나온 표 병합 보다는 쉬웠다. <br>
다만, 이런 조건들로 가지치기를 하는 경우 시간복잡도 안에 통과할 수 있었다는 확신은 없었다. <br>
맞았어도 찜찜한 문제..



[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/150365) 

### 성능 요약

메모리: 71.9 MB, 시간: 0.03 ms

### 구분

코딩테스트 연습 > 2023 KAKAO BLIND RECRUITMENT

### 채점결과

Empty

### 문제 설명

<p><code>n</code> x <code>m</code> 격자 미로가 주어집니다. 당신은 미로의 (x, y)에서 출발해 (r, c)로 이동해서 탈출해야 합니다.</p>

<p>단, 미로를 탈출하는 조건이 세 가지 있습니다.</p>

<ol>
<li>격자의 바깥으로는 나갈 수 없습니다.</li>
<li>(x, y)에서 (r, c)까지 이동하는 거리가 총 <code>k</code>여야 합니다. <strong>이때, (x, y)와 (r, c)격자를 포함해, 같은 격자를 두 번 이상 방문해도 됩니다.</strong></li>
<li>미로에서 탈출한 경로를 문자열로 나타냈을 때, 문자열이 사전 순으로 가장 빠른 경로로 탈출해야 합니다.</li>
</ol>

<p>이동 경로는 다음과 같이 문자열로 바꿀 수 있습니다.</p>

<ul>
<li>l: 왼쪽으로 한 칸 이동</li>
<li>r: 오른쪽으로 한 칸 이동</li>
<li>u: 위쪽으로 한 칸 이동</li>
<li>d: 아래쪽으로 한 칸 이동</li>
</ul>

<p>예를 들어, 왼쪽으로 한 칸, 위로 한 칸, 왼쪽으로 한 칸 움직였다면, 문자열 <code>"lul"</code>로 나타낼 수 있습니다.</p>

<p>미로에서는 인접한 상, 하, 좌, 우 격자로 한 칸씩 이동할 수 있습니다.</p>

<p>예를 들어 다음과 같이 3 x 4 격자가 있다고 가정해 보겠습니다.</p>
<div class="highlight"><pre class="codehilite"><code>....
..S.
E...
</code></pre></div>
<p>미로의 좌측 상단은 (1, 1)이고 우측 하단은 (3, 4)입니다. <code>.</code>은 빈 공간, <code>S</code>는 출발 지점, <code>E</code>는 탈출 지점입니다.</p>

<p>탈출까지 이동해야 하는 거리 <code>k</code>가 5라면 다음과 같은 경로로 탈출할 수 있습니다.</p>

<ol>
<li>lldud</li>
<li>ulldd</li>
<li>rdlll</li>
<li>dllrl</li>
<li>dllud</li>
<li>...</li>
</ol>

<p>이때 dllrl보다 사전 순으로 빠른 경로로 탈출할 수는 없습니다.</p>

<p>격자의 크기를 뜻하는 정수 <code>n</code>, <code>m</code>, 출발 위치를 뜻하는 정수 <code>x</code>, <code>y</code>, 탈출 지점을 뜻하는 정수 <code>r</code>, <code>c</code>, 탈출까지 이동해야 하는 거리를 뜻하는 정수 <code>k</code>가 매개변수로 주어집니다. 이때, 미로를 탈출하기 위한 경로를 return 하도록 solution 함수를 완성해주세요. <strong>단, 위 조건대로 미로를 탈출할 수 없는 경우 <code>"impossible"</code>을 return 해야 합니다.</strong></p>

<hr>

<h5>제한사항</h5>

<ul>
<li>2 ≤ <code>n</code> (= 미로의 세로 길이) ≤ 50</li>
<li>2 ≤ <code>m</code> (= 미로의 가로 길이) ≤ 50</li>
<li>1 ≤ <code>x</code> ≤ <code>n</code></li>
<li>1 ≤ <code>y</code> ≤ <code>m</code></li>
<li>1 ≤ <code>r</code> ≤ <code>n</code></li>
<li>1 ≤ <code>c</code> ≤ <code>m</code></li>
<li>(<code>x</code>, <code>y</code>) ≠ (<code>r</code>, <code>c</code>)</li>
<li>1 ≤ <code>k</code> ≤ 2,500</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>m</th>
<th>x</th>
<th>y</th>
<th>r</th>
<th>c</th>
<th>k</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>3</td>
<td>4</td>
<td>2</td>
<td>3</td>
<td>3</td>
<td>1</td>
<td>5</td>
<td><code>"dllrl"</code></td>
</tr>
<tr>
<td>2</td>
<td>2</td>
<td>1</td>
<td>1</td>
<td>2</td>
<td>2</td>
<td>2</td>
<td><code>"dr"</code></td>
</tr>
<tr>
<td>3</td>
<td>3</td>
<td>1</td>
<td>2</td>
<td>3</td>
<td>3</td>
<td>4</td>
<td><code>"impossible"</code></td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<p>문제 예시와 동일합니다.</p>

<p><strong>입출력 예 #2</strong></p>

<p>미로의 크기는 2 x 2입니다. 출발 지점은 (1, 1)이고, 탈출 지점은 (2, 2)입니다.</p>

<p>빈 공간은 <code>.</code>, 출발 지점을 <code>S</code>, 탈출 지점을 <code>E</code>로 나타내면 다음과 같습니다.</p>
<div class="highlight"><pre class="codehilite"><code>S.
.E
</code></pre></div>
<p>미로의 좌측 상단은 (1, 1)이고 우측 하단은 (2, 2)입니다.</p>

<p>탈출까지 이동해야 하는 거리 <code>k</code>가 2이므로 다음과 같은 경로로 탈출할 수 있습니다.</p>

<ol>
<li>rd</li>
<li>dr</li>
</ol>

<p><code>"dr"</code>이 사전 순으로 가장 빠른 경로입니다. 따라서 <code>"dr"</code>을 return 해야 합니다.</p>

<p><strong>입출력 예 #3</strong></p>

<p>미로의 크기는 3 x 3입니다. 출발 지점은 (1, 2)이고, 탈출 지점은 (3, 3)입니다.</p>

<p>빈 공간은 <code>.</code>, 출발 지점을 <code>S</code>, 탈출 지점을 <code>E</code>로 나타내면 다음과 같습니다.</p>
<div class="highlight"><pre class="codehilite"><code>.S.
...
..E
</code></pre></div>
<p>미로의 좌측 상단은 (1, 1)이고 우측 하단은 (3, 3)입니다.</p>

<p>탈출까지 이동해야 하는 거리 <code>k</code>가 4입니다. 이때, 이동 거리가 4이면서, <code>S</code>에서 <code>E</code>까지 이동할 수 있는 경로는 존재하지 않습니다.</p>

<p>따라서 <code>"impossible"</code>을 return 해야 합니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
