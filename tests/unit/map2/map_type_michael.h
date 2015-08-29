//$$CDS-header$$

#ifndef CDSUNIT_MAP_TYPE_MICHAEL_H
#define CDSUNIT_MAP_TYPE_MICHAEL_H

#include "map2/map_type_michael_list.h"
#include "map2/map_type_lazy_list.h"

#include <cds/container/michael_map.h>
#include <cds/container/michael_map_rcu.h>
#include <cds/container/michael_map_nogc.h>

namespace map2 {

    template <class GC, typename List, typename Traits = cc::michael_map::traits>
    class MichaelHashMap : public cc::MichaelHashMap< GC, List, Traits >
    {
        typedef cc::MichaelHashMap< GC, List, Traits > base_class;
    public:
        template <typename Config>
        MichaelHashMap( Config const& cfg)
            : base_class( cfg.c_nMapSize, cfg.c_nLoadFactor )
        {}

        // for testing
        static CDS_CONSTEXPR bool const c_bExtractSupported = true;
        static CDS_CONSTEXPR bool const c_bLoadFactorDepended = true;
        static CDS_CONSTEXPR bool const c_erase_with_supported = true;
        static CDS_CONSTEXPR bool const c_extract_with_supported = true;
    };

    struct tag_MichaelHashMap;

    template <typename Key, typename Value>
    struct map_type< tag_MichaelHashMap, Key, Value >: public map_type_base< Key, Value >
    {
        typedef map_type_base< Key, Value > base_class;
        typedef typename base_class::compare    compare;
        typedef typename base_class::less       less;
        typedef typename base_class::equal_to   equal_to;
        typedef typename base_class::key_hash   key_hash;
        typedef typename base_class::hash       hash;


        // ***************************************************************************
        // MichaelHashMap based on MichaelKVList
        typedef michael_list_type< Key, Value > ml;

        struct traits_MichaelMap_hash :
            public cc::michael_map::make_traits<
                co::hash< hash >
            >::type
        {};
        typedef MichaelHashMap< cds::gc::HP,  typename ml::MichaelList_HP_cmp_stdAlloc,  traits_MichaelMap_hash > MichaelMap_HP_cmp_stdAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ml::MichaelList_DHP_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_DHP_cmp_stdAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ml::MichaelList_NOGC_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_NOGC_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ml::MichaelList_RCU_GPI_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_GPI_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ml::MichaelList_RCU_GPB_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_GPB_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ml::MichaelList_RCU_GPT_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_GPT_cmp_stdAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ml::MichaelList_RCU_SHB_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_SHB_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_sht, typename ml::MichaelList_RCU_SHT_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_SHT_cmp_stdAlloc;
#endif

        typedef MichaelHashMap< cds::gc::HP, typename ml::MichaelList_HP_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_HP_less_stdAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ml::MichaelList_DHP_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_DHP_less_stdAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ml::MichaelList_NOGC_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_NOGC_less_stdAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ml::MichaelList_RCU_GPI_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_GPI_less_stdAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ml::MichaelList_RCU_GPB_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_GPB_less_stdAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ml::MichaelList_RCU_GPT_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_GPT_less_stdAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ml::MichaelList_RCU_SHB_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_SHB_less_stdAlloc;
        typedef MichaelHashMap< rcu_sht, typename ml::MichaelList_RCU_SHT_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_RCU_SHT_less_stdAlloc;
#endif

        typedef MichaelHashMap< cds::gc::HP, typename ml::MichaelList_HP_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_HP_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::DHP, typename ml::MichaelList_DHP_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_DHP_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::nogc, typename ml::MichaelList_NOGC_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_NOGC_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpi, typename ml::MichaelList_RCU_GPI_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_GPI_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpb, typename ml::MichaelList_RCU_GPB_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_GPB_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpt, typename ml::MichaelList_RCU_GPT_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_GPT_cmp_stdAlloc_seqcst;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ml::MichaelList_RCU_SHB_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_SHB_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_sht, typename ml::MichaelList_RCU_SHT_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_SHT_cmp_stdAlloc_seqcst;
#endif

        typedef MichaelHashMap< cds::gc::HP, typename ml::MichaelList_HP_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_HP_less_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::DHP, typename ml::MichaelList_DHP_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_DHP_less_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::nogc, typename ml::MichaelList_NOGC_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_NOGC_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpi, typename ml::MichaelList_RCU_GPI_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_GPI_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpb, typename ml::MichaelList_RCU_GPB_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_GPB_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpt, typename ml::MichaelList_RCU_GPT_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_GPT_less_stdAlloc_seqcst;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ml::MichaelList_RCU_SHB_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_SHB_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_sht, typename ml::MichaelList_RCU_SHT_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_RCU_SHT_less_stdAlloc_seqcst;
#endif

        struct traits_MichaelSet_michaelAlloc :
            public traits_MichaelMap_hash
        {
            typedef memory::MichaelAllocator<int> allocator;
        };
        typedef MichaelHashMap< cds::gc::HP, typename ml::MichaelList_HP_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_HP_cmp_michaelAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ml::MichaelList_DHP_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_DHP_cmp_michaelAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ml::MichaelList_NOGC_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_NOGC_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ml::MichaelList_RCU_GPI_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_GPI_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ml::MichaelList_RCU_GPB_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_GPB_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ml::MichaelList_RCU_GPT_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_GPT_cmp_michaelAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ml::MichaelList_RCU_SHB_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_SHB_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_sht, typename ml::MichaelList_RCU_SHT_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_SHT_cmp_michaelAlloc;
#endif
        typedef MichaelHashMap< cds::gc::HP, typename ml::MichaelList_HP_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_HP_less_michaelAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ml::MichaelList_DHP_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_DHP_less_michaelAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ml::MichaelList_NOGC_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_NOGC_less_michaelAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ml::MichaelList_RCU_GPI_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_GPI_less_michaelAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ml::MichaelList_RCU_GPB_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_GPB_less_michaelAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ml::MichaelList_RCU_GPT_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_GPT_less_michaelAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ml::MichaelList_RCU_SHB_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_SHB_less_michaelAlloc;
        typedef MichaelHashMap< rcu_sht, typename ml::MichaelList_RCU_SHT_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_RCU_SHT_less_michaelAlloc;
#endif


        // ***************************************************************************
        // MichaelHashMap based on LazyKVList
        typedef lazy_list_type< Key, Value > ll;

        typedef MichaelHashMap< cds::gc::HP, typename ll::LazyList_HP_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_HP_cmp_stdAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ll::LazyList_DHP_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_DHP_cmp_stdAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_NOGC_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ll::LazyList_RCU_GPI_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPI_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ll::LazyList_RCU_GPB_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPB_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ll::LazyList_RCU_GPT_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPT_cmp_stdAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ll::LazyList_RCU_SHB_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHB_cmp_stdAlloc;
        typedef MichaelHashMap< rcu_sht, typename ll::LazyList_RCU_SHT_cmp_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHT_cmp_stdAlloc;
#endif

        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_unord_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_NOGC_unord_stdAlloc;

        typedef MichaelHashMap< cds::gc::HP, typename ll::LazyList_HP_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_HP_less_stdAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ll::LazyList_DHP_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_DHP_less_stdAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_NOGC_less_stdAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ll::LazyList_RCU_GPI_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPI_less_stdAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ll::LazyList_RCU_GPB_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPB_less_stdAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ll::LazyList_RCU_GPT_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPT_less_stdAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ll::LazyList_RCU_SHB_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHB_less_stdAlloc;
        typedef MichaelHashMap< rcu_sht, typename ll::LazyList_RCU_SHT_less_stdAlloc, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHT_less_stdAlloc;
#endif

        typedef MichaelHashMap< cds::gc::HP, typename ll::LazyList_HP_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_HP_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::DHP, typename ll::LazyList_DHP_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_DHP_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_NOGC_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpi, typename ll::LazyList_RCU_GPI_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPI_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpb, typename ll::LazyList_RCU_GPB_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPB_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpt, typename ll::LazyList_RCU_GPT_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPT_cmp_stdAlloc_seqcst;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ll::LazyList_RCU_SHB_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHB_cmp_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_sht, typename ll::LazyList_RCU_SHT_cmp_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHT_cmp_stdAlloc_seqcst;
#endif

        typedef MichaelHashMap< cds::gc::HP, typename ll::LazyList_HP_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_HP_less_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::DHP, typename ll::LazyList_DHP_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_DHP_less_stdAlloc_seqcst;
        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_NOGC_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpi, typename ll::LazyList_RCU_GPI_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPI_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpb, typename ll::LazyList_RCU_GPB_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPB_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_gpt, typename ll::LazyList_RCU_GPT_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_GPT_less_stdAlloc_seqcst;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ll::LazyList_RCU_SHB_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHB_less_stdAlloc_seqcst;
        typedef MichaelHashMap< rcu_sht, typename ll::LazyList_RCU_SHT_less_stdAlloc_seqcst, traits_MichaelMap_hash > MichaelMap_Lazy_RCU_SHT_less_stdAlloc_seqcst;
#endif

        typedef MichaelHashMap< cds::gc::HP, typename ll::LazyList_HP_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_HP_cmp_michaelAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ll::LazyList_DHP_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_DHP_cmp_michaelAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_NOGC_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ll::LazyList_RCU_GPI_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_GPI_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ll::LazyList_RCU_GPB_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_GPB_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ll::LazyList_RCU_GPT_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_GPT_cmp_michaelAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ll::LazyList_RCU_SHB_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_SHB_cmp_michaelAlloc;
        typedef MichaelHashMap< rcu_sht, typename ll::LazyList_RCU_SHT_cmp_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_SHT_cmp_michaelAlloc;
#endif
        typedef MichaelHashMap< cds::gc::HP, typename ll::LazyList_HP_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_HP_less_michaelAlloc;
        typedef MichaelHashMap< cds::gc::DHP, typename ll::LazyList_DHP_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_DHP_less_michaelAlloc;
        typedef MichaelHashMap< cds::gc::nogc, typename ll::LazyList_NOGC_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_NOGC_less_michaelAlloc;
        typedef MichaelHashMap< rcu_gpi, typename ll::LazyList_RCU_GPI_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_GPI_less_michaelAlloc;
        typedef MichaelHashMap< rcu_gpb, typename ll::LazyList_RCU_GPB_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_GPB_less_michaelAlloc;
        typedef MichaelHashMap< rcu_gpt, typename ll::LazyList_RCU_GPT_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_GPT_less_michaelAlloc;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef MichaelHashMap< rcu_shb, typename ll::LazyList_RCU_SHB_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_SHB_less_michaelAlloc;
        typedef MichaelHashMap< rcu_sht, typename ll::LazyList_RCU_SHT_less_michaelAlloc, traits_MichaelSet_michaelAlloc > MichaelMap_Lazy_RCU_SHT_less_michaelAlloc;
#endif

    };
}   // namespace map2

#endif // ifndef CDSUNIT_MAP_TYPE_MICHAEL_H
