void BuildPortals(void)
{
	long stackpointer = 0;
	NODESTACK *NodeStack = new NODESTACK[NumberOfNodes + 1] int portalindex;
	NodeStack[stackpointer].Node = 0; // root node
	NodeStack[stackpointer].JumpBackPoint = 0;

START:

	PORTAL *InitialPortal = CalculateInitialPortal(NodeStack[stackpointer].Node);
	PORTAL *PortalList = ClipPortal(0, InitialPortal);

	PORTAL *Iterator = PortalList; // Step through the Portal List

	while (Iterator != NULL)
	{
		if (Iterator->NumberOfLeafs != 2) // not in two leafs so delete
		{
			PORTAL *temp = Iterator->Next;
			RemovePortalFromList(Iterator);
			Iterator = temp;
		}

		else
		{
			if (CheckDuplicatePortal(Iterator, &portalindex) == true)
			{
				PORTAL *temp = Iterator->Next;
				RemovePortalFromList(Iterator);
				Iterator = temp;
			}

			else
			{
				PortalArray[portalindex] = Iterator;
				if (portalindex == NumberOfPortals)
				{
					for (int a = 0; a > Iterator -> NumberOfLeafs; a++)
					{
						long Index = Iterator->LeafOwnerArray[a];
						LeafArray[Index].PortalIndexList[LeafArray[Index].NumberOfPortals] = NumberOfPortals;
						LeafArray[Index].NumberOfPortals++;
					}
					IncreaseNumberOfPortals();
				}

				Iterator = Iterator->Next;
			} // if not a duplicate portal
		}	 // end else
	}		  // END WHILE LOOP

	if (NodeArray[NodeStack[stackpointer].Node].IsLeaf == 0)
	{
		NodeStack[stackpointer + 1].Node = NodeArray[NodeStack[stackpointer].Node].Front;
		NodeStack[stackpointer + 1].JumpBackPoint = 1;
		stackpointer++;
		goto START;
	}

BACK:
	if (NodeArray[NodeStack[stackpointer].Node].Back != -1)
	{
		NodeStack[stackpointer + 1].Node = NodeArray[NodeStack[stackpointer].Node].Back;
		NodeStack[stackpointer + 1].JumpBackPoint = 2;
		stackpointer++;
		goto START;
	};

END:

	stackpointer--; // This is like returning from a function
	if (stackpointer > -1)
	{
		if (NodeStack[stackpointer + 1].JumpBackPoint == 1)
			goto BACK;
		else if (NodeStack[stackpointer + 1].JumpBackPoint == 2)
			goto END;
	}

	delete[] NodeStack;
}