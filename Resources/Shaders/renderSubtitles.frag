void main() {
    vec4 res = vec4(0.0);
    vec2 texCoordAbs = dstDims * texCoord.st;

    for (int i = 0; i < NTEXTURES; i++) {
        // We should not perform loops with non-constant limit in GLES, this fails in at least ANGLE 47!
        if (i == ntextures) break;
        if (all(greaterThanEqual(texCoordAbs, subCoords[i])) &&
            all(lessThanEqual(texCoordAbs, subCoords[i] + subDims[i]))) {
            float alpha = texture2D(subTex, (texCoordAbs - subCoords[i] + vec2(0.0, float(i) * IMG_H)) / vec2(IMG_W, IMG_H * float(NTEXTURES))).r;
            vec4 col = vec4(vec3(1.0), alpha); // Set color to white (1.0, 1.0, 1.0)
            col *= subColors[i]; // Apply the specific color
            res = col + res * (1.0 - col.a);
        }
    }

    gl_FragColor = res;
}