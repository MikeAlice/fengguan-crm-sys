package com.zeroone.star.commodity.tools;

/**
 * @author 张二发
 */
public class RedisTool {
    /**
     * 商品分类名称集合的key goods:category:set:name
     */
    public static final String GOODS_CATEGORY_NAME_SET_KEY = "goods:category:set:name";
    /**
     * 商品分类简称集合的key goods:category:set:shortName
     */
    public static final String GOODS_CATEGORY_SHORT_NAME_KEY = "goods:category:set:shortName";
    public static final String GOODS_CATEGORY_NAME_TREE_KEY = "goods:category:name:tree";
    private static final String GOODS_CATEGORY_KEY = "goods:category:id:";
    /**
     * 商品分类的有序集合的key goods:category:zset
     */
    public static final String GOODS_CATEGORY_ZSET_KEY = "goods:category:zset";

    /**
     * 获取商品分类集合的key goods:category:id
     *
     * @return 商品分类集合的key
     */
    public static String getGoodsCategoryKey(int goodsCategoryId) {
        return GOODS_CATEGORY_KEY + goodsCategoryId;
    }

    /**
     * 商品sku名称集合的key goods:sku:list:id
     */
    public static final String GOODS_SKU_LIST_ID = "goods:sku:list:id";

    public static String getGoodsCategoryListKey(int pageNum, int pageSize) {
        return GOODS_CATEGORY_KEY + pageNum + ":" + pageSize;
    }
}
