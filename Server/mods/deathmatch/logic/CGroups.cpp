/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CGroups.cpp
 *  PURPOSE:     Entity (dummy) group manager class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"

CDummy* CGroups::Create(CElement* pParent)
{
    return new CDummy(this, pParent);
}

CDummy* CGroups::CreateFromXML(CElement* pParent, CXMLNode& Node, CEvents* pEvents)
{
    CDummy* const pTemp = new CDummy(this, pParent);
    
    if (!pTemp->LoadFromCustomData(pEvents, Node))
    {
        delete pTemp;
        return nullptr;
    }

    return pTemp;
}

void CGroups::Delete(CDummy* pDummy)
{
    delete pDummy;
}

void CGroups::DeleteAll(void)
{
    DeletePointersAndClearList(m_List);
}

void CGroups::RemoveFromList(CDummy* pDummy)
{
    m_List.remove(pDummy);
}
