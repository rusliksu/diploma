#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

struct Tree
{
	int maxsize;
	int *nodetyp;
	char *node;
	int *param;
	int paramn;
}/*tree*/;

Tree Treemas[2];

Tree tree_genrnd(float maxtreedepth, int *symbols[])
{
	Tree tree;
	int nn[2] = { sizeof(symbols[1]), sizeof(symbols[2]) };
	int n = 2 ^ int(floor(maxtreedepth));
	int *vt = new int[n];
	char *vn = new char[n];
	/*for (int i = 0; i < n; i++) vt[i] = 0;
	for (int i = 0; i < n; i++) vn[i] = 0;*/
	for (int i = 1; i < (n - 1) / 2; i++)
	{
		vt[i] = tree_genrndsymb(1 / 2, *nn);
		vn[i] = tree_genrndsymb(1 / 2, *nn);
	}
	for (int i = (n + 1) / 2; i < n; i++)
	{
		vt[i] = tree_genrndsymb(1, *nn);
		vn[i] = tree_genrndsymb(1, *nn);
	}
	tree.maxsize = n;
	tree.nodetyp = vt;
	tree.node = vn;
	tree.param[int(floor((n + 1) / 2))] = {};
	tree.paramn = 0;
	return tree;
}

int tree_genrndsymb(int p0, int nn)
{
	int nodetyp;
	char node;
	srand(time(NULL));
	int random = rand() % 1;
	if (random < p0)
		nodetyp = 2;
	else
		nodetyp = 1;
	node = char(floor(nn*random)) + 1;
	return node, nodetyp;
}

Tree tree_getsubtree(Tree treein, int rix)
{
	Tree tree;
	tree = treein;
	if (rix>treein.maxsize)
	return;
	//int vin[] = new int[];
	//int vout[] = new int[];
	int vin[] = { rix };
	int vout[] = { 1 };
	int iix = 1;
	while (vin[iix] <= treein.maxsize)
	{
		tree.nodetyp(vout[iix]) = treein.nodetyp(vin[iix]);
		tree.node(vout[iix]) = treein.node(vin[iix]);
		vin[] = { vin, vin[ iix ] *2, vin[iix] *2 + 1 };
		vout[] = { vout, vout[iix] * 2, vout[iix] * 2 + 1 };
		iix = iix + 1;
	}
	return tree;
}

Tree tree_inserttree(Tree Treerc, Tree treedst, int dstix, int nvar)
{
	Tree tree;
	srand(time(NULL));
	int random = rand() % 1;
	tree = treedst;
	if (dstix > treedst.maxsize) return ;
	int vin[] = { 1 };
	int vout[] = { dstix };
	int iix = 1;
	while (vin[iix] <= Treerc.maxsize & vout[iix] <= tree.maxsize)
	{
		tree.nodetyp(vout[iix]) = Treerc.nodetyp(vin[iix]);
		tree.node(vout[iix]) = Treerc.node(vin[iix]);
		vin[] = { vin, vin[iix] * 2, vin[iix] * 2 + 1 };
		vout[] = { vout, vout[iix] * 2, vout[iix] * 2 + 1 };
		iix = iix + 1;
	}
	for (int i = (tree.maxsize = 1) / 2; i < tree.maxsize; i++)
	{
		if (tree.nodetyp[i] = 1)
		{
			tree.nodetyp[i] = 2;
			tree.node[i] = char(floor(nvar*random) + 1);
		}
	}
	return tree;
}

int recombinate_Tree(Tree treein1, Tree treein2, int mode, int *symbols[])
{
	Tree tree1 = treein1;
	Tree tree2 = treein2;
	int nn[2] = { sizeof(symbols[1]), sizeof(symbols[2]) };
	switch (mode)
	{
	case 1:

	}
}

Tree tree_mutate(Tree treein, int *symbols[])
{
	Tree tree;
	srand(time(NULL));
	int random = rand() % 1;
	tree = treein;
	int nn[2] = { sizeof(symbols[1]), sizeof(symbols[2]) };
	[n, v] = tree_size(tree); //
	int i = v(int(floor(random*sizeof(v)) + 1));
	if (i < (tree.maxsize + 1) / 2 & random < 0.5)
	{
		tree.nodetyp[i] = tree_genrndsymb(tree.nodetyp(i)==1, *nn);
		tree.node[i] = tree_genrndsymb(tree.nodetyp(i)==1, *nn);
	}
	else
		while (tree.node(i) == treein.node(i) & tree.nodetyp(i) == treein.nodetyp(i))
		{
			tree.nodetyp[i] = tree_genrndsymb(tree.nodetyp(i) != 1, *nn);
			tree.node[i] = tree_genrndsymb(tree.nodetyp(i) != 1, *nn);
		}
}

void main()dsadsasadsda
{

}

