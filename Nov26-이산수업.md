#10장 
* Directed graph
* a : Source has only outgoing edges
* z : sink has only imcoming edges
* 0 <= Cij : i to j 의 edge의 capacity (말하자면 파이프의 굵기!)

# Flow
* it cannot be negative because flow cannot reverse the flow!
* 0 <= Fij <= Cij
* then Fji = 0
* Flow도 weight고 Capacity도 weight!
```
consider a graph G=(V,E)
v ∈ V - {a, z}
Σ(i∈V) F(i,v) = Σ(i∈V)F(v,i)
```

# Thm 10.15
* a에서 나가는 총량 = z에 들어오는 총량
* Show that
```
Σ(i∈V)Σ(j∈V)Fij - Σ(i∈V)Σ(j∈V)Fji = 0
```
* proof :
```
= Σ(j∈V)Faj + Σ(j∈V)Fzj + Σ(i∈V-{a,z})Σ(j∈V)Fij
 - Σ(j∈V)Fja + Σ(j∈V)Fjz + Σ(i∈V-{a,z})Σ(j∈V)Fji
 = Σ(j∈V)Faj - Σ(j∈V)Fjz
 conservation에 의해 =0
 ```
 * So we will call *Σ(j∈V)Faj* Value of the flow
 * If we have multiple sources then we assume that we have one super source supplys to multiple sources
 * Same trick used in multiple sinks
 * Maximized flow:
 * F = F(i,j) is called Maximal flow
 * assume P(a,z) = (a, v1, v2, ... , z)
	* a->v1->v2<-v3<-v4->v5->z
	* 우리는 a에서 z로 최대한 많은 flow를 보내고 싶기 떄문에 ->방향을 properly oriented라고 정의한다.
	* 0<=F12<=C12, 0<=F43<=C43, ...
	* 보낼 수 있는 Flow의 최댓값은 병목 현상이 일어나는 지점이다.
* i->j
	* 0<=Fij<=Cij
	* Cij-Fij : 여유가 있는가?
* k<-l
	* Clk>=Flk>=0
	* 여유 : properly oriented되어있지 않으므로 Flk만큼 흐르는 유량을 *탕감*시켜주는게 최선
* a->v1->v2<-v3->z
	* C01-F01 = Δ01
	* C12-F12 = Δ12
	* F32 = Δ23
	* C3z - F3z = Δ3z
	* Δ=min(Δ01,Δ12,Δ23,Δ3z)
	* ~F01 = F01+Δ
	* ~F12 = F12 + Δ
	* ~F32 = F32 - Δ
	* ~F3z = F3z + Δ
* a-3,1->b<-4,1-c-3,2->d-5,1->z
path | Δ
-----|-----
a-b | 2
b-c | 3
c-d | 1
d-z | 4
* so resulting path is
	* a-3,2->b<-4,0-c-3,3->d-5,2->z
* max flow algorithm *max_flow(a, z, C, v, n)* 
	* where a : 공급 업체, 수요가 있는만큼 무한히 생산
	* v : 상인에게 전달될 수 있는 양
```
//초기화
Fij = 0 for each (i,j)
	while(1){
		for(i=0 to n)
		{
			predecessor(vi) = Φ;
			val(vi) = 0//확보된 물량
			predecessor(a) = "-"
			val(a) = ∞
			let U = {a} // 물량을 공급할 의사가 있는 집합, 혹은 labeled vertex
			while(value(z) == 0)
				if(U == Φ)
					return F
				choose v∈U
					U = U-{v}
					Δ = val(v)
					/////
					for each edge(v,w)with val(w)==0
						if(Fvw<Cvw)
							predecessor(w) = v
							val(w) = min(Δ, Cvw-Fvw)
							U = U ∪ {w}
					for each edge(w,v) with val(w)==0
						if(Fwv > 0)
							predecessor(w) = v
							val(w) = min(Δ, Fwv)
							U = U ∪ {w}
		}
	}
```