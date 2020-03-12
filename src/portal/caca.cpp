PORTAL *ClipPortal(long Node, PORTAL *Portal)
{
	PORTAL *PortalList = NULL, *FrontPortalList = NULL, *BackPortalList = NULL, *Iterator = NULL, *FrontSplit = NULL, *BackSplit = NULL;
	switch (ClassifyPoly(&PlaneArray[NodeArray[Node].Plane], (POLYGON *)Portal))
	{

	case CP_ONPLANE:
		Send down Both Trees if (NodeArray[Node].IsLeaf != 0) // this is a Leaf Node
		{
			// The Front is a Leaf
			Portal->LeafOwnerArray[Portal->NumberOfLeafs] = NodeArray[Node].Front;
			Portal->NumberOfLeafs++;
			Portal->Next = NULL;
			Portal->Prev = NULL;
			FrontPortalList = Portal;
		}
		else
		{
			// Send the Portal Down the Front List and get returned a list of PortalFragments that survived the Front Tree
			FrontPortalList = ClipPortal(NodeArray[Node].Front, Portal);
		}

		// Then send each fragment down the back tree.
		if (FrontPortalList == NULL)
			return NULL;
		if (NodeArray[Node].Back == -1)
			return FrontPortalList;

		while (FrontPortalList != NULL)
		{
			PORTAL *tempnext = FrontPortalList->Next;
			BackPortalList = NULL;
			BackPortalList = ClipPortal(NodeArray[Node].Back, FrontPortalList);

			if (BackPortalList != NULL)
			{
				Iterator = BackPortalList;
				while (Iterator->Next != NULL)
				{
					Iterator = Iterator->Next;
				}
				// attach the last fragment to the first fragment from a previos loop. Iterator->Next=PortalList;
				if (PortalList != NULL)
				{
					PortalList->Prev = Iterator;
				}
				PortalList = BackPortalList; // portal List now points at the current complete list of fragment collected from each loop
			}

			FrontPortalList = tempnext;
		}
		return PortalList;
		break;

	case CP_FRONT: // Either send it down the front tree or add it to the portal list because it has come out //Empty Space

		if (NodeArray[Node].IsLeaf == 0)
		{
			PortalList = ClipPortal(NodeArray[Node].Front, Portal);
			return PortalList;
		}
		else // The Front Node is a Empty Leaf so Add it to the Portal List
		{
			Portal->LeafOwnerArray[Portal->NumberOfLeafs] = NodeArray[Node].Front;
			Portal->NumberOfLeafs++;
			Portal->Next = NULL;
			Portal->Prev = NULL;
			return Portal;
		}
		break;

	case CP_BACK: // either asend it downthe back tree or Delete it if no back tree exists

		if (NodeArray[Node].Back != -1)
		{
			PortalList = ClipPortal(NodeArray[Node].Back, Portal);
			return PortalList;
		}
		else
		{
			DeletePortal(Portal);
			return NULL;
		}
		break;

	case CP_SPANNING:

		FrontSplit = new PORTAL;
		BackSplit = new PORTAL;
		ZeroMemory(FrontSplit, sizeof(PORTAL));
		ZeroMemory(BackSplit, sizeof(PORTAL));
		SplitPortal(Portal, &PlaneArray[NodeArray[Node].Plane], FrontSplit, BackSplit);
		DeletePortal(Portal);
		if (NodeArray[Node].IsLeaf == 0)
		{
			FrontPortalList = ClipPortal(NodeArray[Node].Front, FrontSplit);
		}
		else // Its about to get pushed into a Leaf
		{
			FrontSplit->LeafOwnerArray[FrontSplit->NumberOfLeafs] = NodeArray[Node].Front;
			FrontSplit->NumberOfLeafs++;
			FrontSplit->Prev = NULL;
			FrontSplit->Next = NULL;
			FrontPortalList = FrontSplit;
		}

		if (NodeArray[Node].Back != -1) // the backsplit is in solid space
		{
			BackPortalList = ClipPortal(NodeArray[Node].Back, BackSplit);
		}
		else // delete it its in solid space
		{
			DeletePortal(BackSplit);
		}
		if (FrontPortalList != NULL) // Find the End of the list and attach it to Front Back List
		{
			Iterator = FrontPortalList;
			while (Iterator->Next != NULL)
			{
				Iterator = Iterator->Next;
			}
			if (BackPortalList != NULL)
			{
				Iterator->Next = BackPortalList;
				BackPortalList->Prev = Iterator;
			}
			return FrontPortalList;
		} // there is something in the front list

		else ////There is nothing in the front list
		{
			if (BackPortalList != NULL)
				return BackPortalList;
			return NULL;
		}

		return NULL;
		break;

	default:
		return NULL;
		break;
	} //end switch
	return NULL;
}
