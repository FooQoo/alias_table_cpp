## Alias method in C++

### What is "Alias Method"?
Alias法は任意の離散確率分布に従うサンプルの生成を効率的に行う手法です．
Alias法では，その準備と使用するメモリのオーダーがO(n)であるが，サンプル一つ一つはO(1)で生成することができます．

Alias法では，以下の離散分布の分解に関係する以下の定理を根幹としています．

```
p(x)を任意の離散分布の確率質量関数とするとき，p(.)はn個の2点分布q_i(.), i=1,2,...,nの等加重和として表せる．
p(i) = 1/n sum_i=1_n q_i(.)
```

### Alias Method
- 初期準備
次の手順に従い，a_k, v_kを求める．
1. v_k \leftallow K_{p_k}
2. v_k \leq 1を満たすkの集合をL，そうでないkの集合をSとするとき，LおよびSが空集合とならない限り，a-cを繰り返す．
    a. L, Sから1つずつ任意の要素を選択し，それぞれl, sとする．
    b. a_s \leftallow l, v_l \leftallow v_l - (1.0 - v_s)
    c. v_l < 1ならばlをLからSへ移す．

- 乱数発生
1. (0, K)上の一様乱数uを発生
2. u < v_kならばX \leftallow k, そうでないなら X \leftallow a_k

Alias法は，離散分布をK個のベルヌーイ分布として表現する．
一様乱数によって，一つのベルヌーイ分布を決定した後，確率vkでkをとり，確率1-vkでakをとる．

### Refference
[E-musu's Memo](https://e-musu.github.io/alias-method.html)