/**
 * Checks whether the specified ray intersects with the AABB.
 *
 * The slab method algorithm is used to detect the intersection. Note
 * that if the ray is parallel to either one of the axis, the corresponding
 * t values will be either -Infinity or +Infinity depending on where the
 * ray origin is in relation to the bounding planes. For example, if the
 * ray origin is above all bounding planes, t values will be -Infinity;
 * if the ray origin is below all bounding planes, t values will be +Infinity;
 * otherwise tmin and tmax values will be -Infinity and +Infinity respectively.
 */
static bool aabbIntersection(const Aabb &aabb, const Ray &ray)
{
    const qreal tx1 = (aabb.min.x() - ray.origin.x()) / ray.origin.normal.x();
    const qreal tx2 = (aabb.max.x() - ray.origin.x()) / ray.origin.normal.x();

    qreal tmin = std::min(tx1, tx2);
    qreal tmax = std::max(tx1, tx2);

    const qreal ty1 = (aabb.min.y() - ray.origin.y()) / ray.origin.normal.y();
    const qreal ty2 = (aabb.max.y() - ray.origin.y()) / ray.origin.normal.y();

    tmin = std::max(tmin, std::min(ty1, ty2));
    tmax = std::min(tmax, std::max(ty1, ty2));

    const qreal tz1 = (aabb.min.z() - ray.origin.z()) / ray.origin.normal.z();
    const qreal tz2 = (aabb.max.z() - ray.origin.z()) / ray.origin.normal.z();

    tmin = std::max(tmin, std::min(tz1, tz2));
    tmax = std::min(tmax, std::max(tz1, tz2));

    return tmin < tmax;
}
