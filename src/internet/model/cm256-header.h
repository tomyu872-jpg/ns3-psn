#ifndef CM256_HEADER_H
#define CM256_HEADER_H

#include "ns3/header.h"
#include "ns3/nstime.h"
#include <iostream>

namespace ns3 {

class Cm256Header : public Header 
{
public:

  Cm256Header(uint32_t blockId = 0, uint16_t symbolId = 0);

  void SetBlockId(uint32_t id);
  void SetSymbolId(uint16_t id);
  uint32_t GetBlockId() const;
  uint16_t GetSymbolId() const;

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void Print (std::ostream &os) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);

private:
  uint32_t m_blockId;
  uint16_t m_symbolId;
};

} // namespace ns3

#endif // CM256_HEADER_H
