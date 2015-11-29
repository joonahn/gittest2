#10�� 
* Directed graph
* a : Source has only outgoing edges
* z : sink has only imcoming edges
* 0 <= Cij : i to j �� edge�� capacity (�����ڸ� �������� ����!)

# Flow
* it cannot be negative because flow cannot reverse the flow!
* 0 <= Fij <= Cij
* then Fji = 0
* Flow�� weight�� Capacity�� weight!
```
consider a graph G=(V,E)
v �� V - {a, z}
��(i��V) F(i,v) = ��(i��V)F(v,i)
```

# Thm 10.15
* a���� ������ �ѷ� = z�� ������ �ѷ�
* Show that
```
��(i��V)��(j��V)Fij - ��(i��V)��(j��V)Fji = 0
```
* proof :
```
= ��(j��V)Faj + ��(j��V)Fzj + ��(i��V-{a,z})��(j��V)Fij
 - ��(j��V)Fja + ��(j��V)Fjz + ��(i��V-{a,z})��(j��V)Fji
 = ��(j��V)Faj - ��(j��V)Fjz
 conservation�� ���� =0
 ```
 * So we will call *��(j��V)Faj* Value of the flow
 * If we have multiple sources then we assume that we have one super source supplys to multiple sources
 * Same trick used in multiple sinks
 * Maximized flow:
 * F = F(i,j) is called Maximal flow
 * assume P(a,z) = (a, v1, v2, ... , z)
	* a->v1->v2<-v3<-v4->v5->z
	* �츮�� a���� z�� �ִ��� ���� flow�� ������ �ͱ� ������ ->������ properly oriented��� �����Ѵ�.
	* 0<=F12<=C12, 0<=F43<=C43, ...
	* ���� �� �ִ� Flow�� �ִ��� ���� ������ �Ͼ�� �����̴�.
* i->j
	* 0<=Fij<=Cij
	* Cij-Fij : ������ �ִ°�?
* k<-l
	* Clk>=Flk>=0
	* ���� : properly oriented�Ǿ����� �����Ƿ� Flk��ŭ �帣�� ������ *����*�����ִ°� �ּ�
* a->v1->v2<-v3->z
	* C01-F01 = ��01
	* C12-F12 = ��12
	* F32 = ��23
	* C3z - F3z = ��3z
	* ��=min(��01,��12,��23,��3z)
	* ~F01 = F01+��
	* ~F12 = F12 + ��
	* ~F32 = F32 - ��
	* ~F3z = F3z + ��
* a-3,1->b<-4,1-c-3,2->d-5,1->z
path | ��
-----|-----
a-b | 2
b-c | 3
c-d | 1
d-z | 4
* so resulting path is
	* a-3,2->b<-4,0-c-3,3->d-5,2->z
* max flow algorithm *max_flow(a, z, C, v, n)* 
	* where a : ���� ��ü, ���䰡 �ִ¸�ŭ ������ ����
	* v : ���ο��� ���޵� �� �ִ� ��
```
//�ʱ�ȭ
Fij = 0 for each (i,j)
	while(1){
		for(i=0 to n)
		{
			predecessor(vi) = ��;
			val(vi) = 0//Ȯ���� ����
			predecessor(a) = "-"
			val(a) = ��
			let U = {a} // ������ ������ �ǻ簡 �ִ� ����, Ȥ�� labeled vertex
			while(value(z) == 0)
				if(U == ��)
					return F
				choose v��U
					U = U-{v}
					�� = val(v)
					/////
					for each edge(v,w)with val(w)==0
						if(Fvw<Cvw)
							predecessor(w) = v
							val(w) = min(��, Cvw-Fvw)
							U = U �� {w}
					for each edge(w,v) with val(w)==0
						if(Fwv > 0)
							predecessor(w) = v
							val(w) = min(��, Fwv)
							U = U �� {w}
		}
	}
```