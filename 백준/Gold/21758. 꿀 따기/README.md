# [Gold V] 꿀 따기 - 21758 

[문제 링크](https://www.acmicpc.net/problem/21758) 

꿀벌이 2마리인 점을 제대로 읽지 않아 푸는데 오래 걸린 문제 <Br>
벌이 2마리리면 이야기는 쉽다. <br>
일단 새로운 벌이 배치되었을 때의 장단점을 이해해야 한다. <br>
새로 벌이 배치되면 그 벌의 다음 칸 부터 벌집까지 추가로 꿀을 딸 수 있는 대신, 새로 배치된 벌의 위치에 있는 꿀은 딸 수가 없다. <br>
그래서 어떤 벌을 배치했을 때, 실제로 얻어지는 꿀의 양은 벌 다음 칸 ~ 벌집까지의 합에서 **벌 자신이 서 있는 칸을 빼준 값이다.** <br>
꼭 빼주어야 제대로 그 값을 구할 수 있다. <Br>
하여간 이런 식으로 벌집이 가장 왼쪽 일때, 가장 오른쪽 일때 각각 벌 한마리를 오른쪽 끝, 왼쪽 끝에 두고, <Br>
위에서 말한 공식으로 발 한마리를 더 놓을 위치를 찾는다. <br>
이렇게 구해진 두가지 상황에서의 최대 꿀 값과, 벌이 양쪽 끝에 있고, 벌집이 가운데 있는 상황까지 3가지 경우를 비교하여 최대값을 반환하면 된다. <br>
두 벌 사이에 벌집이 위치한 경우엔, 벌을 양쪽 끝에 두고, 꿀이 가장 많은 칸을 꿀집으로 정하면 된다. <br>
왜냐하면 벌이 양쪽 끝에 있는 경우의 최대 꿀 채취량은, 양 옆 끝칸을 제외한 전체 꿀 양에다가 벌집칸 꿀을 더한 값이기 때문이다. <br>
벌집칸의 꿀을 더해주는 이유는 벌집칸의 꿀은 두번 채취되기 때문이다!
 
### 성능 요약

메모리: 3196 KB, 시간: 44 ms

### 분류

많은 조건 분기(case_work), 그리디 알고리즘(greedy), 누적 합(prefix_sum)

### 문제 설명

<p>아래와 같이 좌우로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 장소가 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/7eac9e04-f000-482d-9ad5-05cc2363df05/-/preview/" style="width: 353px; height: 56px;"></p>

<p>장소들 중 서로 다른 두 곳을 골라서 벌을 한 마리씩 둔다. 또, 다른 한 장소를 골라서 벌통을 둔다. 아래 그림에서 연한 회색의 장소는 벌이 있는 장소이고 진한 회색의 장소는 벌통이 있는 장소이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8ca82402-c379-40cd-902d-9ecc24c35d1f/-/preview/" style="width: 353px; height: 56px;"></p>

<p>두 마리 벌은 벌통으로 똑바로 날아가면서 지나가는 모든 칸에서 꿀을 딴다. 각 장소에 적힌 숫자는 벌이 지나가면서 꿀을 딸 수 있는 양이다.</p>

<ol>
	<li>두 마리가 모두 지나간 장소에서는 두 마리 모두 표시된 양 만큼의 꿀을 딴다. (벌통이 있는 장소에서도 같다.)</li>
	<li>벌이 시작한 장소에서는 어떤 벌도 꿀을 딸 수 없다.</li>
</ol>

<p>위의 그림과 같이 배치된 경우 두 마리의 벌 모두 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn><mo>+</mo><mn>1</mn><mo>+</mo><mn>4</mn><mo>+</mo><mn>9</mn><mo>+</mo><mn>9</mn><mo>=</mo><mn>27</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4 + 1 + 4 + 9 + 9 = 27$</span></mjx-container>의 꿀을 따서, 전체 꿀의 양은 54가 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a9794fde-7a1b-4c4d-82b5-f1b8e7daaa73/-/preview/" style="width: 353px; height: 56px;"></p>

<p>위의 그림과 같이 배치된 경우 왼쪽 장소에서 출발한 벌은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>9</mn><mo>+</mo><mn>4</mn><mo>+</mo><mn>4</mn><mo>+</mo><mn>9</mn><mo>+</mo><mn>9</mn><mo>=</mo><mn>35</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$9 + 4 + 4 + 9 + 9 = 35$</span></mjx-container>의 꿀을 따고 오른쪽 장소에서 출발한 벌은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn><mo>+</mo><mn>9</mn><mo>+</mo><mn>9</mn><mo>=</mo><mn>22</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4 + 9 + 9 = 22$</span></mjx-container>의 꿀을 따므로, 전체 꿀의 양은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>57</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$57$</span></mjx-container>이 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5b264635-fc6b-498a-af76-bbe08197ab32/-/preview/" style="width: 353px; height: 56px;"></p>

<p>위의 그림과 같은 경우는 전체 꿀의 양이 31이 된다.</p>

<p>장소들의 꿀 양을 입력으로 받아 벌들이 딸 수 있는 가능한 최대의 꿀의 양을 계산하는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 번째 줄에 장소의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>다음 줄에 왼쪽부터 각 장소에서 꿀을 딸 수 있는 양이 공백 하나씩을 사이에 두고 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 가능한 최대의 꿀의 양을 출력한다.</p>

