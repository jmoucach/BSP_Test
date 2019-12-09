void BuildBspTree(long Node, POLYGON *PolyList)
{
	POLYGON *polyTest = NULL;
	POLYGON *FrontList = NULL;
	POLYGON *BackList = NULL;
	POLYGON *NextPolygon = NULL;
	POLYGON *FrontSplit = NULL;
	POLYGON *BackSplit = NULL;
	D3DXVECTOR3 vec1, vec2;
	D3DXVECTOR3 a, b;
	float result;

	NodeArray[Node].Plane = SelectBestSplitter(PolyList);
	polyTest = PolyList;
	NodeArray[Node].BoundingBox.BoxMax = D3DXVECTOR3(-40000, -40000, -40000);
	NodeArray[Node].BoundingBox.BoxMin = D3DXVECTOR3(40000, 40000, 40000);

	while (polyTest != NULL)
	{
		NextPolygon = polyTest->Next; // remember because polytest->Next will be altered

		switch (ClassifyPoly(&PlaneArray[NodeArray[Node].Plane], polyTest))
		{
		case CP_ONPLANE:
			a = PlaneArray[NodeArray[Node].Plane].Normal;
			b = polyTest->Normal;
			result = (float)fabs((a.x - b.x) + (a.y - b.y) + (a.z - b.z));
			if (result < 0.1)
			{
				polyTest->Next = FrontList;
				FrontList = polyTest;
			}
			else
			{
				polyTest->Next = BackList;
				BackList = polyTest;
			}
			break;

		case CP_FRONT:
			polyTest->Next = FrontList;
			FrontList = polyTest;
			break;

		case CP_BACK:
			polyTest->Next = BackList;
			BackList = polyTest;
			break;

		case CP_SPANNING:
			FrontSplit = new POLYGON;
			BackSplit = new POLYGON;
			ZeroMemory(FrontSplit, sizeof(POLYGON));
			ZeroMemory(BackSplit, sizeof(POLYGON));
			SplitPolygon(polyTest, &PlaneArray[NodeArray[Node].Plane], FrontSplit, BackSplit);
			FrontSplit->BeenUsedAsSplitter = polyTest->BeenUsedAsSplitter;
			BackSplit->BeenUsedAsSplitter = polyTest->BeenUsedAsSplitter;
			FrontSplit->TextureIndex = polyTest->TextureIndex;
			BackSplit->TextureIndex = polyTest->TextureIndex;

			DeletePolygon(polyTest);

			FrontSplit->Next = FrontList;
			FrontList = FrontSplit;
			BackSplit->Next = BackList;
			BackList = BackSplit;
			break;
		default:
			break;

		} //switch
		polyTest = NextPolygon;
	} // end while loop

	int count = 0;
	POLYGON *tempf = FrontList;
	while (tempf != NULL)
	{
		if (tempf->BeenUsedAsSplitter == false)
			count++;
		tempf = tempf->Next;
	}

	CalculateBox(&NodeArray[Node].BoundingBox, FrontList);
	BOUNDINGBOX LeafBox = NodeArray[Node].BoundingBox;
	CalculateBox(&NodeArray[Node].BoundingBox, BackList);

	if (count == 0)
	{
		POLYGON *Iterator = FrontList;
		POLYGON *Temp;
		LeafArray[NumberOfLeafs].StartPolygon = NumberOfPolygons;
		while (Iterator != NULL)
		{
			PolygonArray[NumberOfPolygons] = *Iterator;
			IncreaseNumberOfPolygons();
			Temp = Iterator;
			Iterator = Iterator->Next;
			delete Temp;
		}
		LeafArray[NumberOfLeafs].EndPolygon = NumberOfPolygons;
		LeafArray[NumberOfLeafs].BoundingBox = LeafBox;
		NodeArray[Node].Front = NumberOfLeafs;
		NodeArray[Node].IsLeaf = 1;
		IncreaseNumberOfLeafs();
	}
	else
	{
		NodeArray[Node].IsLeaf = 0;
		NodeArray[Node].Front = NumberOfNodes + 1;
		IncreaseNumberOfNodes();
		BuildBspTree(NumberOfNodes, FrontList);
	}

	if (BackList == NULL)
	{
		NodeArray[Node].Back = -1;
	}
	else
	{
		NodeArray[Node].Back = NumberOfNodes + 1;
		IncreaseNumberOfNodes();
		BuildBspTree(NumberOfNodes, BackList);
	}

} // end function