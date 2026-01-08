#include "cm256-header.h"
#include "ns3/address-utils.h"

namespace ns3 {

Cm256Header::Cm256Header(uint32_t blockId, uint16_t symbolId)
    : m_blockId(blockId), m_symbolId(symbolId) {}

void Cm256Header::SetBlockId(uint32_t id) { m_blockId = id; }
void Cm256Header::SetSymbolId(uint16_t id) { m_symbolId = id; }
uint32_t Cm256Header::GetBlockId() const { return m_blockId; }
uint16_t Cm256Header::GetSymbolId() const { return m_symbolId; }

TypeId
Cm256Header::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::Cm256Header")
    .SetParent<Header> ()
    .SetGroupName ("Network");
  return tid;
}

TypeId
Cm256Header::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

void
Cm256Header::Print (std::ostream &os) const
{
  os << "BlockId=" << m_blockId << " SymbolId=" << m_symbolId;
}

uint32_t
Cm256Header::GetSerializedSize (void) const
{
  // blockId (4字节) + symbolId (2字节)
  return 4 + 2;
}

void
Cm256Header::Serialize (Buffer::Iterator start) const
{
  start.WriteHtonU32 (m_blockId);
  start.WriteHtonU16 (m_symbolId);
}

uint32_t
Cm256Header::Deserialize (Buffer::Iterator start)
{
  m_blockId = start.ReadNtohU32 ();
  m_symbolId = start.ReadNtohU16 ();
  return GetSerializedSize ();
}


} // namespace ns3
